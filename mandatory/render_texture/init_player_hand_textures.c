#include "../../includes/Cub3D.h"

static void	build_filename(char *filename, char *base, int frame_num, char *ext)
{
	int	n;
	int	m;

	n = 0;
	while (base[n] != '\0')
	{
		filename[n] = base[n];
		n++;
	}
	filename[n++] = '0' + (frame_num + 1);
	m = 0;
	while (ext[m] != '\0')
	{
		filename[n++] = ext[m];
		m++;
	}
	filename[n] = '\0';
}

static void	load_frame_texture(t_data_game *_game, int i, char *filename)
{
	int	width;
	int	height;

	_game->player_hand->img[i]->img = mlx_xpm_file_to_image(_game->_mlx,
			filename, &width, &height);
	if (!_game->player_hand->img[i]->img)
	{
		printf("Error: Even fallback texture failed to load\n");
		syntax_error(ALLOC);
	}
	_game->player_hand->img[i]->width = width;
	_game->player_hand->img[i]->height = height;
}

static void	init_player_hand_memory(t_data_game *_game)
{
	_game->player_hand = malloc(sizeof(t_player_hand));
	if (!_game->player_hand)
		syntax_error(ALLOC);
	_game->player_hand->num_frames = 4;
	_game->player_hand->current_frame = 0;
	_game->player_hand->img = malloc(sizeof(t_imag *)
			* _game->player_hand->num_frames);
	if (!_game->player_hand->img)
		syntax_error(ALLOC);
}

void	init_player_hand_textures(t_data_game *_game)
{
	int i;
	char *filename;

	filename = malloc(50 * sizeof(char));
	init_player_hand_memory(_game);
	i = 0;
	while (i < _game->player_hand->num_frames)
	{
		_game->player_hand->img[i] = malloc(sizeof(t_imag));
		if (!_game->player_hand->img[i])
			syntax_error(ALLOC);
		build_filename(filename, "./textures/shotgun/anim_", i, ".xpm");
		load_frame_texture(_game, i, filename);
		i++;
	}
}