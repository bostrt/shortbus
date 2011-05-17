package state;

/**
 * Pause
 * 
 * Pause state. Press the P button to exit it.
 * 
 * @author Robert Bost <bostrt at gmail dot com>
 */

import java.awt.Color;
import java.awt.Font;

import org.newdawn.slick.GameContainer;
import org.newdawn.slick.Graphics;
import org.newdawn.slick.Input;
import org.newdawn.slick.SlickException;
import org.newdawn.slick.UnicodeFont;
import org.newdawn.slick.font.effects.ColorEffect;
import org.newdawn.slick.state.BasicGameState;
import org.newdawn.slick.state.StateBasedGame;

public class Pause extends BasicGameState
{
	public static final int PAUSE_STATE = 1;
	private UnicodeFont font; 
	private int pausedWidth;
	private int pausedHeight;
	private int otherWidth;
	

	@Override
	public int getID()
	{
		return PAUSE_STATE;
	}

	@Override
	public void init(GameContainer container, StateBasedGame sbg)
		throws SlickException
	{
		font = new UnicodeFont(new Font("Sans", Font.ITALIC, 24));
		font.addAsciiGlyphs();
		font.getEffects().add(new ColorEffect(Color.WHITE));
		font.loadGlyphs();
		pausedWidth = font.getWidth("PAUSED")/2;
		pausedHeight= font.getHeight("PAUSED");
		otherWidth  = font.getWidth("Press 'P' to unpause.")/2;
	}

	@Override
	public void render(GameContainer container, StateBasedGame sbg, Graphics g)
		throws SlickException
	{
		g.setAntiAlias(true);
		font.drawString(container.getWidth()/2-(pausedWidth), container.getHeight()/2, "PAUSED");
		font.drawString(container.getWidth()/2-(otherWidth), container.getHeight()/2+pausedHeight, "Press 'P' to unpause.");
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
