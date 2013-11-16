#pragma once
#include <iostream>
#include <stdlib.h>
#include "Map.cpp"
#include "Structures.cpp"
using namespace std;

class Render
{
	private:
		Map *level;
		Player player;
		View view;

	public:
		/*!
		 * constructor for renderer 
		 */
		Render(View v)
		{
			view = v;
			level = new Map(view);

			player.x = 1;
			player.y = 1;

			level -> getView(view.current, player.x-(view.width/2), player.y-(view.height/2));
		}

		/*!
		 * @brief takes the current frame, compares to previous frame to efficiently render
		 */
		void render()
		{
			system("clear");
			//for each tile update
			for (short index=0; index < (view.height * view.width); index++)
			{
				//if the tile has changed update it
				if (view.previous[index] != view.current[index])
				{
					//get the type of tile
					switch(view.current[index])
					{
						case ' ':
							//open tile
							break;
						case 'W':
							//wall
							break;
						case 'V':
							//void
							break;
						case 'c':
							//your character
							break;

					}
					cout << view.current[index];	
				}
				//Otherwise (you would) do nothing
				else
				{
					cout << view.current[index];
				}

				//create line breaks for rows in ASCII
				if ( (index % view.width) == (view.width - 1) )
				{
					cout << endl;
				}
			}

			//displays instructions and flushes buffer
			cout << "use wasd to move" << endl;
			cout.flush();

			//copy current array to previous array
			for (short index = 0; index < view.height * view.width; index++)
			{
				view.previous[index] = view.current[index];
			}
		}

		/*!
		 * @brief Keyboard input event handler
		 */
		void move(char value)
		{
			short newX = player.x;
			short newY = player.y;

			//gets character codes
			switch (value)
			{
				case 'w':
				case 'W':
					newY--;
					break;
				case 'a':
				case 'A':
					newX--;
					break;
				case 's':
				case 'S':
					newY++;
					break;
				case 'd':
				case 'D':
					newX++;
					break;
			}

			//checks if the Player can move to the next space
			if (level -> spaceIsOpen(newX, newY))
			{
				level -> setTile(' ',player.x,player.y);
				level -> setTile('c',newX,newY);
				player.x = newX;
				player.y = newY;
				//get current frame
				level -> getView(view.current,player.x-(view.width/2),player.y-(view.height/2));
				//renders frame
				render();
			}
		}

};
