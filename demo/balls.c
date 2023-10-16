#include "node-list.h"
#include "queue-extended.h"
#include <stdio.h>

typedef enum
{
	STATE_EXIT, /* 0 */
	STATE_IDLE,
	STATE_PUSH,
	STATE_PLAY
} state_e;

typedef struct game
{
	char input;
	state_e state;
	queue_t *balls;
	int removed;
} game_t;

game_t *game_init(void)
{
	game_t *game = malloc(sizeof(game_t));
	game->state = STATE_IDLE;
	game->input = game->removed = 0;
	game->balls = queue_init(sizeof(int));
	return game;
}

void game_input(game_t *game)
{
	game->input = getc(stdin);
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
void game_remove(game_t *game, node_list_t *start, int count)
{
	game->removed = count;
	for (; count; queue_remove_after(start), --count);
}

static
void game_play(game_t *game)
{
	int count = 0;
	int color = -1;
	node_list_t *start = NULL;
	game->removed = 0;
	for (node_list_t *ball = game->balls->tail->next, *pball = game->balls->tail;
			ball != game->balls->tail;
			ball = ball->next, pball = pball->next)
	{
		if (*(int *) ball->val != color)
		{
			if (count < 3)
			{
				color = *(int *) ball->val;
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
			queue_add(game->balls, &(int){game->input-'0'});
			game->state = STATE_IDLE;
			break;

		case STATE_PLAY:
			game_play(game);
			game->state = STATE_IDLE;
			break;

		case STATE_IDLE:
		case STATE_EXIT:
			break;
	}
	return game->state;
}

static
void ball_print(FILE *out, void *ball)
{
	fprintf(out, "%hhd", *(char *) ball);
}

void game_update(game_t *game)
{
	printf("Removed: %d\n", game->removed);
	queue_fprint(stdout, ball_print, game->balls);
	printf("\n");
}

void game_free(game_t *game)
{
	queue_free(game->balls);
	free(game);
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
