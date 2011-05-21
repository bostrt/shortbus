import org.newdawn.slick.*;
import org.newdawn.slick.state.*;

import state.*;

public class ShortBus extends StateBasedGame
{
	
	public static void main(String[] args) throws SlickException 
	{
		ShortBus bus = new ShortBus("ShortBus");
		AppGameContainer game = new AppGameContainer(bus, 800, 600, false);
		game.start();
		bus.enterState(Play.PLAY_STATE);
	}

	public ShortBus(String name)
	{
		super(name);
	}

	@Override
	public void initStatesList(GameContainer arg0) throws SlickException
	{
		addState(new Play());
		addState(new Pause());
		addState(new Garage());
	}

}