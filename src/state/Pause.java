package state;

import org.newdawn.slick.GameContainer;
import org.newdawn.slick.Graphics;
import org.newdawn.slick.Input;
import org.newdawn.slick.SlickException;
import org.newdawn.slick.state.BasicGameState;
import org.newdawn.slick.state.StateBasedGame;

public class Pause extends BasicGameState
{
	public static final int PAUSE_STATE = 1;

	@Override
	public int getID()
	{
		return PAUSE_STATE;
	}

	@Override
	public void init(GameContainer container, StateBasedGame sbg)
			throws SlickException
	{
		
	}

	@Override
	public void render(GameContainer container, StateBasedGame sbg, Graphics g)
		throws SlickException
	{
		g.drawString("Paused\nPress 'p' to unpause.", container.getHeight()/2, container.getWidth()/3);

	}

	@Override
	public void update(GameContainer container, StateBasedGame sbg, int delta)
			throws SlickException
	{
		Input in = container.getInput();
		if(in.isKeyPressed(Input.KEY_P)){
			sbg.enterState(Play.PLAY_STATE);
		}
	}

}
