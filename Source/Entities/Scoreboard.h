#pragma once
#include "Entity.h"
#include <TextDisplay.h>

class Scoreboard : public Entity
{
public:
	Scoreboard();
	virtual ~Scoreboard();

	void WriteHighscore();

	void Reset();
	void IncrementScore(int amount);

	void SetScoreDisplay(TextDisplay* display, int value);

private:
	void ReadHighscore();
	void InitAllLabelsAndDisplays();

	int m_score;
	static int m_highscore;
	TextDisplay* m_scoreText;
	TextDisplay* m_highscoreText;

	Entity* m_highscoreDisplay;
	Entity* m_highscoreLabel;
	Entity* m_scoreDisplay;
	Entity* m_scoreLabel;;
};

