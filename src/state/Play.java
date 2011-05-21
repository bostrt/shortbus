package state;
import org.newdawn.slick.Animation;
import org.newdawn.slick.GameContainer;
import org.newdawn.slick.Graphics;
import org.newdawn.slick.Image;
import org.newdawn.slick.Input;
import org.newdawn.slick.SlickException;
import org.newdawn.slick.geom.Polygon;
import org.newdawn.slick.geom.Transform;
import org.newdawn.slick.state.BasicGameState;
import org.newdawn.slick.state.StateBasedGame;
import org.newdawn.slick.tiled.TiledMap;

public class Play extends BasicGameState
{
	
	public static final int PLAY_STATE = 0;
	/**
	 * The collision map indicating which tiles block movement - generated based
	 * on tile properties
	 */
	private boolean[][] blocked;

	/** The offset from the centre of the screen to the top edge in tiles */
	private int topOffsetInTiles;
	/** The offset from the centre of the screen to the left edge in tiles */
	private int leftOffsetInTiles;

	/**
	 * The map that we're going to drive around, Map creation must have property
	 * on buildings and boundary of "blocked" set to "true"
	 */
	private TiledMap map;
	private int tileWidth;
	private Animation shortbus;
	private float x = 2;
	private float y = 2;
	private Polygon bounds;
	private float angle;
	private int widthInTiles;
	private int heightInTiles;

	private float dirX;

	private float dirY;
	private static final float BUS_MOVE_SPEED = 0.003f;
	/** The speed the tank rotates at */
	private static final float BUS_ROTATE_SPEED = 0.2f;

	@Override
	public void update(GameContainer container, StateBasedGame sbg, int delta) throws SlickException
	{
		int tileID = map.getTileId((int)x,(int)y, 0);
		String value = map.getTileProperty(tileID, "garage", "false");
		if("true".equals(value))
		{
			String temp = (map.getTileProperty(tileID, "opening", "none"));
			if(temp.equals("north")){
				tryMove(0,-.25);
			}else if(temp.equals("east")){
				tryMove(.25,0);
			}else if(temp.equals("south")){
				tryMove(0,.25);
			}else if(temp.equals("west")){
				tryMove(-.25,0);
			}else if(temp.equals("none")){
				System.out.println("ERROR ERROR ERROR");
			}
			sbg.enterState(2);
		}
		
		Input input = container.getInput();
		if (input.isKeyDown(Input.KEY_LEFT)) {
			angle -= delta * BUS_ROTATE_SPEED;
			bounds.transform(Transform.createRotateTransform(-BUS_ROTATE_SPEED* delta));
			updateMovementVector();
		}
		if (input.isKeyDown(Input.KEY_RIGHT)) {
			angle += delta * BUS_ROTATE_SPEED;
			bounds.transform(Transform.createRotateTransform(BUS_ROTATE_SPEED* delta));
			updateMovementVector();
		}
		if (input.isKeyDown(Input.KEY_UP)) {
			if (tryMove(dirX * delta * BUS_MOVE_SPEED, dirY * delta* BUS_MOVE_SPEED)) {
				// if we managed to move update the animation
				shortbus.update(delta);
			}
		}
		if (input.isKeyDown(Input.KEY_DOWN)) {
			if (tryMove(-dirX * delta * BUS_MOVE_SPEED, -dirY * delta* BUS_MOVE_SPEED)) {
				// if we managed to move update the animation
				shortbus.update(delta);
			}
		}
		if(input.isKeyPressed(Input.KEY_P)){
			sbg.enterState(Pause.PAUSE_STATE);
		}
		
		if (container.getInput().isKeyDown(Input.KEY_T)) {
			testBlocked();
		}
	}

	private void updateMovementVector()
	{
		dirX = (float) Math.sin(Math.toRadians(angle));
		dirY = (float) -Math.cos(Math.toRadians(angle));
	}

	private boolean blocked(double dx, double dy) {
		int newx=(int)(dx+(.5*(float)shortbus.getHeight()/(float)tileWidth-.25));
		int newy=(int)(dy+(.5*(float)shortbus.getWidth()/(float)tileWidth+.25));
		return blocked[newx][newy];
	}

	private boolean tryMove(double newxx, double newyy){
		float newx = (float) (x + newxx);
		float newy = (float) (y + newyy);

		Polygon test = bounds;
		test = (Polygon) test.transform(Transform.createTranslateTransform((float) (newxx), (float) (newyy)));

		if (!testPolygon(test)) {
			test = bounds;
			test = (Polygon) test.transform(Transform.createTranslateTransform((float) (newxx), 0));
			if (!testPolygon(test)) {
				test = bounds;
				test = (Polygon) test.transform(Transform.createTranslateTransform(0, (float) (newyy)));
				if (!testPolygon(test)) {
					// can't move at all!
					return false;
				} else {
					bounds = test;
					y = newy;
					return true;
				}
			} else {
				bounds = test;
				x = newx;
				return true;
			}
		} else {
			bounds = test;
			x = newx;
			y = newy;
			return true;
		}

	}
	
	private void testBlocked(){
		System.out.println();
		float[] points= bounds.getPoints();	
		boolean test = false;
		for(int i=0; i<points.length; i+=2){
			if(blocked(points[i], points[i+1])) test=true;
			int newx=(int)(points[i]+(.5*(float)shortbus.getHeight()/(float)tileWidth-.25));
		    int newy=(int)(points[i+1]+(.5*(float)shortbus.getWidth()/(float)tileWidth+.25));
			System.out.println();
			System.out.println("NewX: "+ newx);
			System.out.println("NewY: "+ newy);
		}
		System.out.println(test);
		System.out.println(shortbus.getWidth());
		System.out.println(shortbus.getHeight());
	}
	
	private boolean testPolygon(Polygon test)
	{
/*		System.out.println("MaxX: " + test.getMaxX());
		System.out.println("MaxY: " + test.getMaxY());
		System.out.println("MinX: " + test.getMinX());
		System.out.println("MinY: " + test.getMinY());*/
		float[] points= test.getPoints();		
		for(int i=0; i<points.length; i+=2){
			if(blocked(points[i], points[i+1])) return false;
		}
		return true;
	}

	private void createPolygon()
	{
		bounds = new Polygon(
				new float[] {
						(float) (x + .5 * ((float) shortbus.getWidth() / tileWidth)),
						(float) (y + .5 * ((float) shortbus.getHeight() / tileWidth)),
						(float) (x + .5 * ((float) shortbus.getWidth() / tileWidth)),
						(float) (y - .5 * ((float) shortbus.getHeight() / tileWidth)),
						(float) (x - .5 * ((float) shortbus.getWidth() / tileWidth)),
						(float) (y - .5 * ((float) shortbus.getHeight() / tileWidth)),
						(float) (x - .5 * ((float) shortbus.getWidth() / tileWidth)),
						(float) (y + .5 * ((float) shortbus.getHeight() / tileWidth)),
						(float) (x + .5 * ((float) shortbus.getWidth() / tileWidth)),
						(float) (y + .5 * ((float) shortbus.getHeight() / tileWidth)), });
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see org.newdawn.slick.Game#render(org.newdawn.slick.GameContainer,
	 * org.newdawn.slick.Graphics)
	 */
	@Override
	public void render(GameContainer container, StateBasedGame sbg, Graphics g)	throws SlickException{
		int playerTileX = (int) x;
		int playerTileY = (int) y;

		// caculate the offset of the player from the edge of the tile. As the
		// player moves around this
		// varies and this tells us how far to offset the tile based rendering
		// to give the smooth
		// motion of scrolling
		int playerTileOffsetX = (int) ((playerTileX - x) * tileWidth);
		int playerTileOffsetY = (int) ((playerTileY - y) * tileWidth);

		// render the section of the map that should be visible. Notice the -1
		// and +3 which renders
		// a little extra map around the edge of the screen to cope with tiles
		// scrolling on and off
		// the screen
		map.render(playerTileOffsetX - (tileWidth / 2), 
				playerTileOffsetY- (tileWidth / 2), 
				playerTileX - leftOffsetInTiles - 1,
				playerTileY - topOffsetInTiles - 1, 
				widthInTiles + 5, heightInTiles +5,
				1, false);

		// draw entities relative to the player that must appear in the centre
		// of the screen

		g.translate(400 - (int) (x), 300 - (int) (y));

		drawBus(g, x, y, angle);
		// draw other entities here if there were any

		g.resetTransform();

		/*
		 * bg.draw(0,0); map.render(0,0); //shortbus=
		 * shortbus.getScaledCopy(scale); //BREAKS THE CODE!!! DON'T USE!!! NO
		 * CLUE WHY!!!! shortbus.drawCentered(x,y);
		 */
	}

	/**
	 * Draw a single bus to the game
	 * 
	 * @param g
	 *            The graphics context on which we're drawing
	 * @param xpos
	 *            The x coordinate in tiles the tank is at
	 * @param ypos
	 *            The y coordinate in tiles the tank is at
	 * @param rot
	 *            The rotation of the tank
	 */
	public void drawBus(Graphics g, float xpos, float ypos, float rot)
	{
		// work out the centre of the tank in rendering coordinates and then
		// spit onto the screen
		int cx = (int) (xpos);
		int cy = (int) (ypos);
		g.rotate((int) (cx + .5 * shortbus.getWidth()),
				(int) (cy + .5 * shortbus.getHeight()), rot);
		shortbus.draw(cx, cy);
		g.rotate(cx, cy, -rot);
	}

	@Override
	public int getID()
	{
		// TODO Auto-generated method stub
		return PLAY_STATE;
	}

	@Override
	public void init(GameContainer arg0, StateBasedGame arg1)
			throws SlickException
	{
		// bg = new Image("src/bg.png");
		shortbus = new Animation();
		shortbus.addFrame(new Image("src/whiteBus.png"), 1);
		shortbus.setAutoUpdate(false);
		map = new TiledMap("src/mapW3.tmx");
		tileWidth = map.getTileHeight();

		// caculate some layout values for rendering the tilemap. How many tiles
		// do we need to render to fill the screen in each dimension and how far
		// is
		// it from the centre of the screen
		widthInTiles = arg0.getWidth() / tileWidth;
		heightInTiles = arg0.getHeight() / tileWidth;
		topOffsetInTiles = (int) heightInTiles / 2;
		leftOffsetInTiles = (int) widthInTiles / 2;
		createPolygon();

		// build a collision map based on tile properties in the TileD map
		blocked = new boolean[map.getWidth()][map.getHeight()];
		for (int i = 0; i < map.getWidth(); i++) {
			for (int j = 0; j < map.getHeight(); j++) {
				int tileID = map.getTileId(i, j, 0);
				String value = map.getTileProperty(tileID, "blocked", "false");
				if ("true".equals(value)) {
					blocked[i][j] = true;
				}
				else
					blocked[i][j] = false;

			}
		}
		updateMovementVector();
	}
}
