class GameEngine
{
private:
    
    //Screen dimension
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;

    //1 second in MS divided by expected frame rate
    const int FRAME_DURATION = 1000 / 60; 

public:
    GameEngine(/* args */);
    ~GameEngine();
};

GameEngine::GameEngine(/* args */)
{
}

GameEngine::~GameEngine()
{
}

void GameEngine::handleEvents()
{

}
