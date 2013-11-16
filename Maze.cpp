#include "Render.cpp"

int main()
{
	//creates a snapshot for view
	View v;
	v.height = 5;
	v.width = 9;
	v.current = new char[v.height * v.width];
	v.previous = new char[v.height * v.width];

	//creates renderer
	Render *app = new Render(v);
	app -> render();

	//
	char letter;
	while (true)
	{
		cin.get(letter);
		app -> move(letter);
	}

	return 0;
}
