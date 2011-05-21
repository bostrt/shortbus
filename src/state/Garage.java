package state;

import org.newdawn.slick.GameContainer;
import org.newdawn.slick.Graphics;
import org.newdawn.slick.Image;
import org.newdawn.slick.Input;
import org.newdawn.slick.SlickException;
import org.newdawn.slick.gui.MouseOverArea;
import org.newdawn.slick.state.BasicGameState;
import org.newdawn.slick.state.StateBasedGame;
public class Garage extends BasicGameState
{
	public static final int GARAGE_STATE=2;
	MouseOverArea ar;
	Image bob;

	@Override
	public int getID() {
		
		return GARAGE_STATE;
	}

	@Override
	public void init(GameContainer container, StateBasedGame sbg)
			throws SlickException {
		bob = new Image("src/blue.png");
		ar = new MouseOverArea(container,new Image("src/blue2.png"), container.getHeight()/2,container.getWidth()/3);
		ar.setMouseOverImage(new Image("src/green2.png"));
	}

	@Override
	public void render(GameContainer container, StateBasedGame sbg, Graphics g)
			throws SlickException {

		ar.render(container, g);
	}

	@Override
	public void update(GameContainer container, StateBasedGame sbg, int delta)
			throws SlickException {
		Input in = container.getInput();
		if(in.isKeyPressed(Input.KEY_ESCAPE)){
			sbg.enterState(Play.PLAY_STATE);
		}
		
	}

}
