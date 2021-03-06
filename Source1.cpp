#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>
#include<iostream>

int idr = 0, idp = 0, i, j,w=1;
int id_real[3][3];
int id_play[3][3];


void check(){
	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++){
			if (id_real[i][j] == id_play[i][j]){
				w++;
				if (w == 9){
					std::cout << "WINNER";

				}
			}
			
		}
	}
	w = 1;
}

int main(){
	
	int movex,movey,mi,mj,temp;
//	int id_r = 0; id_p = 0;
	sf::Sprite pic;
	sf::Sprite grid;
	sf::Sprite empty;


	sf::Sprite repopic[3][3];
	sf::Vector2i repopos[3][3];
	sf::Texture gridtexture;
	sf::Texture pictecture;
	sf::Texture emptytexture;
	sf::Vector2i emptypos;
	bool x_right = true;
	bool x_left = true;
	bool y_down = true;
	bool y_up = true;
	emptypos.x = 200;
	emptypos.y = 200;
	
	

	if (!gridtexture.loadFromFile("grid3.png")){
		std::cout << "Image not found";
	}

	if (!pictecture.loadFromFile("picpuz3.jpg")){
		std::cout << "Image not found";
	}
	if (!emptytexture.loadFromFile("empty.png")){
		std::cout << "Image not found";
	}
	pic.setTexture(pictecture);
	grid.setTexture(gridtexture);
	empty.setTexture(emptytexture);
	
	sf::RenderWindow window;
	window.create(sf::VideoMode(300, 300, 32), "PICPUZ");
	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++){

			id_real[i][j] = idr;
			idr++;
			id_play[2][2] = 8;
			if (i != 2 || j != 2){
				
				if (i != j){
					pic.setTextureRect(sf::IntRect(j * 100, i * 100, 100, 100));
					repopic[i][j] = pic;
					repopos[i][j].x = i * 100;
					repopos[i][j].y = j * 100;

					
					id_play[j][i] = idp;

					idp++;
				}
				else if(i==0){
					pic.setTextureRect(sf::IntRect(0,0, 100, 100));
					repopic[1][1] = pic;
					repopos[1][1].x = i * 100;
					repopos[1][1].y = j * 100;

					id_play[1][1] = idp;

					idp++;

				}
				else if (i==1)
				{
					pic.setTextureRect(sf::IntRect(100,100, 100, 100));
					repopic[0][0] = pic;
					repopos[1][1].x = i * 100;
					repopos[1][1].y = j * 100;

					id_play[0][0] = idp;

					idp++;

				}
			}
			else{
				pic.setTextureRect(sf::IntRect(200, 200, 100, 100));
			}
		}
	}
	
	
	while (window.isOpen()){

		sf::Event event;

		while (window.pollEvent(event)){
			if (event.type == event.Closed){
				window.close();
			}



			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){

				if (x_right == true){
					window.clear();
					movex = emptypos.x - 100;
					movey = emptypos.y;
					mi = movex / 100;
					mj = movey / 100;
					repopos[mi + 1][mj].x = emptypos.x;
					repopos[mi + 1][mj].y = emptypos.y;
					repopic[mi + 1][mj] = repopic[mi][mj];
					repopic[mi][mj] = empty;
					emptypos.x = movex;
					
					temp = id_play[mi+1][mj];
					id_play[mi + 1][mj] = id_play[mi][mj];
					id_play[mi][mj] = temp;
					check();
					std::cout << "emptypos x:" << emptypos.x << std::endl;
					std::cout << "pic x:" << emptypos.x << std::endl;

					std::cout << "positopn" << id_play[mi + 1][mj] << std::endl;
				
					if (emptypos.x == 0){
						x_right = false;
					//	x_left = true;
					}
					else
					{
						x_right = true;
						x_left = true;
					}

				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){

				if (x_left == true){
					window.clear();
					movex = emptypos.x + 100;
					movey = emptypos.y;
					mi = movex / 100;
					mj = movey / 100;
					repopos[mi - 1][mj].x = emptypos.x;
					repopos[mi - 1][mj].y = emptypos.y;
					repopic[mi - 1][mj] = repopic[mi][mj];
					repopic[mi][mj] = empty;
					emptypos.x = movex;

					temp = id_play[mi - 1][mj];
					id_play[mi - 1][mj] = id_play[mi][mj];
					id_play[mi][mj] = temp;
					check();


					std::cout << "emptypos x:" << emptypos.x << std::endl;
					std::cout << "pic x:" << emptypos.x << std::endl;
					//emptypos.y=mo
					if (emptypos.x == 200){
						x_left = false;
						//x_right = true;
					}
					else
					{
						x_left = true;
						x_right = true;
					}

				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){

				if (y_down == true){
					window.clear();
					movex = emptypos.x;
					movey = emptypos.y - 100;
					mi = movex / 100;
					mj = movey / 100;
					repopos[mi][mj+1].x = emptypos.x;
					repopos[mi][mj+1].y = emptypos.y;
					repopic[mi][mj+1] = repopic[mi][mj];
					repopic[mi][mj] = empty;
					emptypos.y = movey;

					temp = id_play[mi][mj+1];
					id_play[mi][mj+1] = id_play[mi][mj];
					id_play[mi][mj] = temp;
					check();

					std::cout << "emptypos x:" << emptypos.y << std::endl;
					std::cout << "pic x:" << emptypos.y << std::endl;
					//emptypos.y=mo
					if (emptypos.y == 0){
						y_down = false;
						//x_right = true;
					}
					else
					{
						y_down = true;
						y_up = true;
					}

				}
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){

				if (y_up == true){
					window.clear();
					movex = emptypos.x;
					movey = emptypos.y + 100;
					mi = movex / 100;
					mj = movey / 100;
					repopos[mi][mj - 1].x = emptypos.x;
					repopos[mi][mj - 1].y = emptypos.y;
					repopic[mi][mj - 1] = repopic[mi][mj];
					repopic[mi][mj] = empty;
					emptypos.y = movey;

					temp = id_play[mi][mj-1];
					id_play[mi][mj-1] = id_play[mi][mj];
					id_play[mi][mj] = temp;
					check();

					std::cout << "emptypos x:" << emptypos.y << std::endl;
					std::cout << "pic x:" << emptypos.y << std::endl;
					//emptypos.y=mo
					if (emptypos.y == 200){
						y_up = false;
						//x_right = true;
					}
					else
					{
						y_down = true;
						y_up = true;
					}

				}
			}

			
		}


		window.clear();
		for (i = 0; i < 3; i++){
			for (j = 0; j < 3; j++){
				repopic[i][j].setPosition(repopos[i][j].x, repopos[i][j].y);
				window.draw(repopic[i][j]);

			}
		}
		
		window.draw(grid);
		window.display();
	}
}