function showGameScreen() {
    console.log('Showing GameScreen now.');
    startScreen.visible=false;
    gameScreen.visible=true;
    gameOverScreen.visible=false;
}

function showGameOverScreen() {
    startScreen.visible=false;
    gameScreen.visible=false;
    gameOverScreen.visible=true;
}

