#include "raylib.h"
#include <cstdio>

#include "raylib.h"

struct Gator {
    Rectangle rect;
    Vector2 speed;
    Color color;
};
struct Fisherman {
    Rectangle rect;
    Vector2 speed;
    Color color;
};
struct goodFood{
	Rectangle rect;
	Vector2 speed; 
	Color color;
	bool active;
};
struct badFood{
	Rectangle rect;
	Vector2 speed; 
	Color color;
	bool active;
};

int main(){
 const int windowWidth{1000};
 const int windowHeight{800};
 int num_goodFood{20};
 int num_badFood{10};
InitWindow(windowWidth, windowHeight, "Feed the Gator!");
InitAudioDevice(); 
Gator gator;
gator.rect.height = 50;
gator.rect.width = 50;
gator.color = GREEN;
gator.rect.x = windowWidth/8;
gator.rect.y = windowHeight-gator.rect.height;

Fisherman fisherman;
fisherman.rect.height = 80;
fisherman.rect.width = 50;
fisherman.color = RED;
fisherman.rect.x = windowWidth/1.5;
fisherman.rect.y = windowHeight-fisherman.rect.height;

goodFood goodFood[num_goodFood];
for (int i = 0; i < num_goodFood; i++){
goodFood[i].rect.height= 10;
goodFood[i].rect.width = 10;
goodFood[i].color = YELLOW;
goodFood[i].rect.x = (windowWidth/2)+(fisherman.rect.width/2)-(goodFood[i].rect.width/2);
goodFood[i].rect.y = (windowHeight-fisherman.rect.height)-(goodFood[i].rect.height);
goodFood[i].speed.x = 50;
goodFood[i].speed.y = -10;
goodFood[i].active = false;}
//int shootRate = 0;

badFood badFood[num_badFood];
for (int i = 0; i < num_badFood; i++){
badFood[i].rect.height= 10;
badFood[i].rect.width = 10;
badFood[i].color = PURPLE;
badFood[i].rect.x = (windowWidth/2)+(fisherman.rect.width/2)-(badFood[i].rect.width/2);
badFood[i].rect.y = (windowHeight-fisherman.rect.height)-(badFood[i].rect.height);
badFood[i].speed.x = 50;
badFood[i].speed.y = -10;
badFood[i].active = false;}
//int shootRate = 0;

//Music music = LoadMusicStream("resources/sound.wav");//
//Sound sound = LoadSound("resources/pickUp.wav");//
//PlayMusicStream(music);//

SetTargetFPS(60);  
	while(!WindowShouldClose()){

//UpdateMusicStream(music); 

BeginDrawing();
DrawRectangleRec(gator.rect, gator.color);

DrawRectangleRec(fisherman.rect, fisherman.color);

ClearBackground(WHITE); 
EndDrawing();
}	
CloseAudioDevice(); 
CloseWindow();
}