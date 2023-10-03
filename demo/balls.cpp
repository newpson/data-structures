#include "queue-extended.hpp"
#include <iostream>

enum state_e
{
	STATE_EXIT, /* 0 */
	STATE_IDLE,
	STATE_PUSH,
	STATE_PLAY
};

typedef struct game
{
	char input;
	state_e state;
	queue_t *balls;
	int removed;
} game_t;

game_t * game_init(void)
{
	game_t *game = new game_t;
	game->state = STATE_IDLE;
	game->input = game->removed = 0;
	game->balls = queue_init();
	return game;
}

void game_input(game_t *game)
{
	std::cin >> game->input;
	if (game->input >= '0' && game->input <= '9')
	{
		game->state = STATE_PUSH;
	}
	else if (game->input == 'q')
	{
		game->state = STATE_EXIT;
	}
	else if (game->input == 'n')
	{
		game->state = STATE_PLAY;
	}
	else
	{
		game->state = STATE_IDLE;
	}
}

static
void game_remove(game_t *game, node_t *start, int count)
{
	game->removed = count;
	for (; count; queue_remove_after(start), --count);
}

static
void game_play(game_t *game)
{
	int count = 0;
	int color = -1;
	node_t *start = NULL;
	game->removed = 0;
	for (node_t *ball = game->balls->next, *pball = game->balls;
			ball != game->balls;
			ball = ball->next, pball = pball->next)
	{
		if (ball->val != color)
		{
			if (count < 3)
			{
				color = ball->val;
				start = pball;
				count = 1;
			}
			else
			{
				break;
			}
		}
		else
		{
			++count;
		}
	}
	if (count >= 3)
	{
		game_remove(game, start, count);
	}
}

int game_tick(game_t *game)
{
	switch (game->state)
	{
		case STATE_PUSH:
			queue_push(game->balls, game->input-'0');
			game->state = STATE_IDLE;
			break;

		case STATE_PLAY:
			/* while (game_play(game)); */
			game_play(game);
			game->state = STATE_IDLE;
			break;

		case STATE_IDLE:
		case STATE_EXIT:
			break;
	}
	return game->state;
}

void game_update(game_t *game)
{
	std::cout << "Removed: " << game->removed << std::endl;
	queue_print(game->balls);
}

void game_free(game_t *game)
{
	queue_free(game->balls);
	delete game;
}

int main(void)
{
	game_t *game = game_init();
	while (game_tick(game))
	{
		game_update(game);
		game_input(game);
	}
	game_free(game);
	return 0;
}
