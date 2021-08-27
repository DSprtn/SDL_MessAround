#include "Scoreboard.h"
#include <RenderComponent.h>
#include <TextDisplay.h>
#include "Engine.h"
#include <fstream>


int Scoreboard::m_highscore = 0;

Scoreboard::Scoreboard() : Entity("Scoreboard")
{
	InitAllLabelsAndDisplays();
	if (m_highscore == 0) {
		ReadHighscore();
	}
	SetScoreDisplay(m_highscoreText, m_highscore);
	Reset();
}

Scoreboard::~Scoreboard()
{
	WriteHighscore();
}

void Scoreboard::WriteHighscore()
{
	if (m_score > m_highscore) {
		const std::string filename = "GameData.txt";
		std::ofstream of(filename, std::ios::trunc);
		if (of.is_open()) {
			of << std::to_string(m_score);
			of.close();
		}
	}
}

void Scoreboard::ReadHighscore()
{
	const std::string filename = "GameData.txt";
	std::ifstream fs;
	fs.open(filename, std::ios::in);
	if (fs.fail()) {
		std::ofstream of(filename, std::ios::out);
		if (of.is_open()) {
			of << "0";
			of.close();
		}
		m_highscore = 1;
	}
	else {
		fs >> m_highscore;
	}
	fs.close();
}

void Scoreboard::InitAllLabelsAndDisplays()
{
	SDL_Colour colour = { 255,255,255,255 };

	m_scoreLabel = Engine::Instance->CurrentWorld->CreateEntity<Entity>("ScoreLabel", 150, 38);
	m_scoreLabel->Transform->SetPosition(300, 48);
	auto label = m_scoreLabel->AddComponent<TextDisplay>(m_scoreLabel, "space_invaders.ttf", colour);
	label->SetText("SCORE < 1 >");

	m_scoreDisplay = Engine::Instance->CurrentWorld->CreateEntity<Entity>("ScoreDisplay", 64, 50);
	m_scoreDisplay->Transform->SetPosition(300, 96);
	m_scoreText = m_scoreDisplay->AddComponent<TextDisplay>(m_scoreDisplay, "space_invaders.ttf", colour);
	m_scoreText->SetText("0000");

	m_highscoreLabel = Engine::Instance->CurrentWorld->CreateEntity<Entity>("HighscoreLabel", 150, 38);
	m_highscoreLabel->Transform->SetPosition(660, 48);
	auto highscoreLabelText = m_highscoreLabel->AddComponent<TextDisplay>(m_highscoreLabel, "space_invaders.ttf", colour);
	highscoreLabelText->SetText("HI-SCORE");

	m_highscoreDisplay = Engine::Instance->CurrentWorld->CreateEntity<Entity>("HighscoreLabel", 64, 50);
	m_highscoreDisplay->Transform->SetPosition(660, 96);
	m_highscoreText = m_highscoreDisplay->AddComponent<TextDisplay>(m_highscoreDisplay, "space_invaders.ttf", colour);
	m_highscoreText->SetText("0000");
}

void Scoreboard::Reset()
{
	m_score = 0;
	IncrementScore(0);
}

void Scoreboard::IncrementScore(int amount)
{
	m_score += amount;
	
	SetScoreDisplay(m_scoreText, m_score);
}

void Scoreboard::SetScoreDisplay(TextDisplay* display, int value)
{
	std::string orig = std::to_string(value);
	if (value < 10000) {
		display->SetText(std::string(4 - orig.length(), '0') + orig);
	}
	else {
		display->SetText(orig);
	}
}
