RED    = $(shell printf "\033[31m")
GREEN  = $(shell printf "\033[32m")
YELLOW = $(shell printf "\033[33m")
BLUE   = $(shell printf "\033[34m")
RESET  = $(shell printf "\033[0m")

NAME_MANDATORY = cub3D
NAME_BONUS     = cub3D_bonus

CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g3
RM      = rm -rf

MLX     = -lXext -lX11 -lm
LIBFT_DIR  = libraries/libft
LIBFT      = $(LIBFT_DIR)/libft.a
MLX_LB_DIR = minilibx-linux
MLX_LB     = $(MLX_LB_DIR)/libmlx.a

DIR_OBJ         = obj
DIR_OBJ_BONUS   = obj_bonus
GETLINE_DIR     = libraries/getline

SRC_DIR_MANDATORY    = mandatory
PARSING_DIR_MANDATORY = $(SRC_DIR_MANDATORY)/parsing
RAYCASTING_DIR_MANDATORY = $(SRC_DIR_MANDATORY)/raycasting
RENDER_TEXTURE_DIR_MANDATORY = $(SRC_DIR_MANDATORY)/render_texture
MANAGE_PLAYER_DIR_MANDATORY = $(SRC_DIR_MANDATORY)/manage_player
DRAW_MAPS_DIR_MANDATORY = $(SRC_DIR_MANDATORY)/draw_map

SRC_DIR_BONUS    = bonus
PARSING_DIR_BONUS = $(SRC_DIR_BONUS)/parsing
RAYCASTING_DIR_BONUS = $(SRC_DIR_BONUS)/raycasting
RENDER_TEXTURE_DIR_BONUS = $(SRC_DIR_BONUS)/render_texture
MANAGE_PLAYER_DIR_BONUS = $(SRC_DIR_BONUS)/manage_player
DRAW_MAPS_DIR_BONUS = $(SRC_DIR_BONUS)/draw_map

SRC_GETLINE = $(GETLINE_DIR)/get_next_line.c

SRC_MANDATORY = $(SRC_DIR_MANDATORY)/main.c \
      $(PARSING_DIR_MANDATORY)/check_file_name.c \
      $(PARSING_DIR_MANDATORY)/syntax_error.c \
      $(PARSING_DIR_MANDATORY)/game_parser.c \
      $(PARSING_DIR_MANDATORY)/list_read.c \
      $(PARSING_DIR_MANDATORY)/config_parser.c \
      $(PARSING_DIR_MANDATORY)/validate_textures.c \
      $(PARSING_DIR_MANDATORY)/validate_map_utils.c \
      $(PARSING_DIR_MANDATORY)/check_allowed_characters.c \
      $(PARSING_DIR_MANDATORY)/validate_map.c \
      $(PARSING_DIR_MANDATORY)/destroy_image.c \
      $(MANAGE_PLAYER_DIR_MANDATORY)/player_init.c \
      $(MANAGE_PLAYER_DIR_MANDATORY)/player_control.c \
      $(DRAW_MAPS_DIR_MANDATORY)/mlx_utils.c \
      $(RAYCASTING_DIR_MANDATORY)/mlx_init_data.c \
      $(RAYCASTING_DIR_MANDATORY)/angle_direction.c \
      $(RAYCASTING_DIR_MANDATORY)/collision_check.c \
      $(RAYCASTING_DIR_MANDATORY)/vertical_intersection.c \
      $(RAYCASTING_DIR_MANDATORY)/horizontal_intersection.c \
      $(RAYCASTING_DIR_MANDATORY)/render_background.c \
      $(RAYCASTING_DIR_MANDATORY)/wall_renderer.c \
      $(RAYCASTING_DIR_MANDATORY)/ray_casting.c \
      $(RENDER_TEXTURE_DIR_MANDATORY)/init_textures.c \
      $(RENDER_TEXTURE_DIR_MANDATORY)/texture_management.c

SRC_BONUS = $(SRC_DIR_BONUS)/main.c \
      $(PARSING_DIR_BONUS)/check_file_name.c \
      $(PARSING_DIR_BONUS)/syntax_error.c \
      $(PARSING_DIR_BONUS)/game_parser.c \
      $(PARSING_DIR_BONUS)/list_read.c \
      $(PARSING_DIR_BONUS)/config_parser.c \
      $(PARSING_DIR_BONUS)/validate_textures.c \
      $(PARSING_DIR_BONUS)/validate_map_utils.c \
      $(PARSING_DIR_BONUS)/check_allowed_characters.c\
      $(PARSING_DIR_BONUS)/validate_map.c \
      $(PARSING_DIR_BONUS)/destroy_image.c \
      $(MANAGE_PLAYER_DIR_BONUS)/player_init.c \
      $(MANAGE_PLAYER_DIR_BONUS)/player_control.c \
      $(MANAGE_PLAYER_DIR_BONUS)/manage_door.c \
      $(MANAGE_PLAYER_DIR_BONUS)/mouse_control.c \
      $(DRAW_MAPS_DIR_BONUS)/mlx_utils.c \
      $(DRAW_MAPS_DIR_BONUS)/direction_line.c \
      $(DRAW_MAPS_DIR_BONUS)/minimap.c \
      $(DRAW_MAPS_DIR_BONUS)/minimap_utils.c \
      $(RAYCASTING_DIR_BONUS)/start_simulation.c \
      $(RAYCASTING_DIR_BONUS)/mlx_init_data.c \
      $(RAYCASTING_DIR_BONUS)/angle_direction.c \
      $(RAYCASTING_DIR_BONUS)/collision_check.c \
      $(RAYCASTING_DIR_BONUS)/vertical_intersection.c \
      $(RAYCASTING_DIR_BONUS)/horizontal_intersection.c \
      $(RAYCASTING_DIR_BONUS)/render_background.c \
      $(RAYCASTING_DIR_BONUS)/wall_renderer.c \
      $(RAYCASTING_DIR_BONUS)/ray_casting.c \
      $(RENDER_TEXTURE_DIR_BONUS)/player_hand_animation.c \
      $(RENDER_TEXTURE_DIR_BONUS)/init_player_hand_textures.c \
      $(RENDER_TEXTURE_DIR_BONUS)/init_textures.c \
      $(RENDER_TEXTURE_DIR_BONUS)/texture_management.c \
      $(RENDER_TEXTURE_DIR_BONUS)/display_start_image.c

SRC_MANDATORY += $(SRC_GETLINE)
SRC_BONUS += $(SRC_GETLINE)

OBJ_MANDATORY = $(patsubst $(SRC_DIR_MANDATORY)%.c, $(DIR_OBJ)/%.o, $(filter $(SRC_DIR_MANDATORY)%,$(SRC_MANDATORY))) \
				$(patsubst $(GETLINE_DIR)/%.c, $(DIR_OBJ)/getline/%.o, $(filter $(GETLINE_DIR)/%,$(SRC_MANDATORY)))

OBJ_BONUS = $(patsubst $(SRC_DIR_BONUS)%.c, $(DIR_OBJ_BONUS)/%.o, $(filter $(SRC_DIR_BONUS)%,$(SRC_BONUS))) \
			$(patsubst $(GETLINE_DIR)/%.c, $(DIR_OBJ_BONUS)/getline/%.o, $(filter $(GETLINE_DIR)/%,$(SRC_BONUS)))

all: $(NAME_MANDATORY)

mandatory: $(NAME_MANDATORY)

bonus: $(NAME_BONUS)

$(LIBFT):
	@echo "$(BLUE)Building libft...$(RESET)"
	@make --no-print-directory -C $(LIBFT_DIR)
	@make --no-print-directory -C $(LIBFT_DIR) bonus

$(NAME_MANDATORY): $(DIR_OBJ) $(LIBFT) $(OBJ_MANDATORY)
	@echo "$(GREEN)Linking mandatory executable...$(RESET)"
	$(CC) $(CFLAGS) $(OBJ_MANDATORY) $(MLX) $(LIBFT) $(MLX_LB) -o $(NAME_MANDATORY)
	@echo "$(GREEN)✓ Mandatory $(NAME_MANDATORY) built successfully!$(RESET)"

$(NAME_BONUS): $(DIR_OBJ_BONUS) $(LIBFT) $(OBJ_BONUS)
	@echo "$(GREEN)Linking bonus executable...$(RESET)"
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(MLX) $(LIBFT) $(MLX_LB) -o $(NAME_BONUS)
	@echo "$(GREEN)✓ Bonus $(NAME_BONUS) built successfully!$(RESET)"

$(DIR_OBJ)/%.o: $(SRC_DIR_MANDATORY)%.c
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling mandatory: $<$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

$(DIR_OBJ)/getline/%.o: $(GETLINE_DIR)/%.c
	@mkdir -p $(DIR_OBJ)/getline
	@echo "$(BLUE)Building getline...$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

$(DIR_OBJ_BONUS)/%.o: $(SRC_DIR_BONUS)%.c
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling bonus: $<$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

$(DIR_OBJ_BONUS)/getline/%.o: $(GETLINE_DIR)/%.c
	@mkdir -p $(DIR_OBJ_BONUS)/getline
	@echo "$(YELLOW)Compiling getline for bonus: $<$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)
	@mkdir -p $(DIR_OBJ)/getline

$(DIR_OBJ_BONUS):
	@mkdir -p $(DIR_OBJ_BONUS)
	@mkdir -p $(DIR_OBJ_BONUS)/getline

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	$(RM) $(DIR_OBJ)
	$(RM) $(DIR_OBJ_BONUS)
	@make -C $(LIBFT_DIR) clean
	@echo "$(RED)┏┓┓ ┏┓┏┓┳┓┏┓┳┓$(RESET)" 
	@echo "$(RED)┃ ┃ ┣ ┣┫┃┃┣ ┃┃$(RESET)" 
	@echo "$(RED)┗┛┗┛┗┛┛┗┛┗┗┛┻┛$(RESET)" 

fclean: clean
	@echo "$(RED)Removing executables...$(RESET)"
	@make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME_MANDATORY)
	$(RM) $(NAME_BONUS)

re: fclean all
