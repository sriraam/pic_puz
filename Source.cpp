/*#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>
#include<iostream>
#include<fstream>

void main(){

	int i, j,c=1,o=1,k=1;
	sf::Vector2i tileoriginal[4][4], tilechange[4][4];
	//std::vector<sf::Sprite> tile;
	sf::Sprite grid;
	sf::Sprite tiles,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15;
	sf::Texture pictexture,gridtexture;
	pictexture.loadFromFile("PICPUZ1.jpg");
	gridtexture.loadFromFile("grid.png");
	sf::Vector2i tilepos[3][3];

	tiles.setTexture(pictexture);
	
	grid.setTexture(gridtexture);
	
	
	for (i = 0; i < 4; i++){
		for (j = 0; j < 4; j++){
			if (i != 3 || j != 3){
				
				tileoriginal[i][j].y = j* 100;
				tileoriginal[i][j].x = i * 100;
				std::cout << tileoriginal[i][j].x;
				std::cout << tileoriginal[i][j].y << std::endl;
			}
		}
	}

	

	sf::RenderWindow window;

	window.create(sf::VideoMode(400, 400, 32), "PiCpUz");
	for (i = 0; i < 4; i++){
		for (j = 0; j < 4; j++){
			if (i != 3 || j != 3){
				//intile[i][j] = k;
				tiles.setPosition(i * 100, j * 100);
				tiles.setTextureRect(sf::IntRect(i * 100, j * 100, 100, 100));
				window.draw(tiles);
				//k++;
				//std::cout << intile[i][j];
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
				for (i = 0; i < 4; i++){
					for (j = 0; j < 4; j++){
						//if (i != 3 || j != 3){

						if (tileoriginal[i][j].x == 200){
							if (tileoriginal[i + 1][j].x != 300){
								std::cout << "i:" << i;
								std::cout << "j:" << j;
								window.clear();
								for (i = 0; i < 4; i++){
									for (j = 0; j < 4; j++){
										
										tiles.setPosition(i * 100, j * 100);
										tiles.setTextureRect(sf::IntRect(j * 100, i * 100, 100, 100));
										window.draw(tiles);
										
									}
								}
								tiles.setPosition(i * 300, (j)* 100);
								tiles.setTextureRect(sf::IntRect((j)* 100, (i)* 100, 100, 100));
								window.draw(tiles);
								i = 3;
								j = 3;
							}

						}
						//}
					}
				}
			}
		}

	
		
	
		window.draw(grid);
		window.display();
	}
}
*/