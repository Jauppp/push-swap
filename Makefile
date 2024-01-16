# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 11:29:44 by cdomet-d          #+#    #+#              #
#    Updated: 2024/01/16 14:10:37 by cdomet-d         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
LIB := libft.a

CC := gcc
CFLAGS := -Werror -Wextra -Wall -g3 
CPPFLAGS = -MMD -MP
MAKEFLAGS += --no-print-directory
ARGS = "500 1 498 3 496 5 494 7 492 9 490 11 488 13 486 15 484 17 482 19 480 21 478 23 476 25 474 27 472 29 470 31 468 33 466 35 464 37 462 39 460 41 458 43 456 45 454 47 452 49 450 51 448 53 446 55 444 57 442 59 440 61 438 63 436 65 434 67 432 69 430 71 428 73 426 75 424 77 422 79 420 81 418 83 416 85 414 87 412 89 410 91 408 93 406 95 404 97 402 99 400 101 398 103 396 105 394 107 392 109 390 111 388 113 386 115 384 117 382 119 380 121 378 123 376 125 374 127 372 129 370 131 368 133 366 135 364 137 362 139 360 141 358 143 356 145 354 147 352 149 350 151 348 153 346 155 344 157 342 159 340 161 338 163 336 165 334 167 332 169 330 171 328 173 326 175 324 177 322 179 320 181 318 183 316 185 314 187 312 189 310 191 308 193 306 195 304 197 302 199 300 201 298 203 296 205 294 207 292 209 290 211 288 213 286 215 284 217 282 219 280 221 278 223 276 225 274 227 272 229 270 231 268 233 266 235 264 237 262 239 260 241 258 243 256 245 254 247 252 249 250 251 248 253 246 255 244 257 242 259 240 261 238 263 236 265 234 267 232 269 230 271 228 273 226 275 224 277 222 279 220 281 218 283 216 285 214 287 212 289 210 291 208 293 206 295 204 297 202 299 200 301 198 303 196 305 194 307 192 309 190 311 188 313 186 315 184 317 182 319 180 321 178 323 176 325 174 327 172 329 170 331 168 333 166 335 164 337 162 339 160 341 158 343 156 345 154 347 152 349 150 351 148 353 146 355 144 357 142 359 140 361 138 363 136 365 134 367 132 369 130 371 128 373 126 375 124 377 122 379 120 381 118 383 116 385 114 387 112 389 110 391 108 393 106 395 104 397 102 399 100 401 98 403 96 405 94 407 92 409 90 411 88 413 86 415 84 417 82 419 80 421 78 423 76 425 74 427 72 429 70 431 68 433 66 435 64 437 62 439 60 441 58 443 56 445 54 447 52 449 50 451 48 453 46 455 44 457 42 459 40 461 38 463 36 465 34 467 32 469 30 471 28 473 26 475 24 477 2"

BUILD_DIR := .dir_build
LIBFT_DIR := LIBFT

SRCS := main.c \
		algorithm_utils.c \
		algorithm_clarity.c \
		algorithm.c \
		both_stack_rules.c \
		chained_lists_utils.c \
		index_utils.c \
		parsing_utils.c \
		parsing.c \
		rules.c \
		
OBJS := $(SRCS:%.c=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:%.o=%.d)
RM := rm -rf

all: $(NAME)

$(LIBFT_DIR)/$(LIB): FORCE
	@echo "Making LIBFT..."
	@$(MAKE) -C $(LIBFT_DIR) $(LIB)
	@echo

$(NAME): $(LIBFT_DIR)/$(LIB) $(OBJS)
	@echo
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft
	@echo "All done ! Thanks for waiting :)"
	
$(BUILD_DIR)/%.o:%.c push_swap.h LIBFT/libft.h
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $< 

 -include $(DEPS)

clean: 
	@echo Cleaning...
	$(RM) $(BUILD_DIR) $(LIBFT_DIR)/$(BUILD_DIR)

fclean: clean
	$(RM) $(NAME) $(LIB)
	@echo Bye !
	@echo

re: fclean all

run: all
	@echo "params : $(ARGS)"
	@./$(NAME) $(ARGS) > output.txt
	@echo -n "nb instructions : "
	@awk '/sa|sb|ss|ra|rb|rr|rra|rrb|rrr|pa|pb/' output.txt | wc -l

display: run
	@awk '/------------------------------------------------------------/{found = 1} \
	found' output.txt | cat

seg: all
	@echo "params : $(ARGS)"
	@valgrind ./$(NAME) $(ARGS) > output.txt

leaks: all
	@echo "params : $(ARGS)"
	@valgrind -s --leak-check=full ./$(NAME) $(ARGS)

debug: all
	@echo "Launching debugger"
	@echo "params : $(ARGS)"
	@gdb -tui --args ./$(NAME) $(ARGS)

help:
	@echo "Make \t\t makes push_swap.exe"
	@echo "Make clean \t deletes object files & dependencies"
	@echo "Make debug \t launches GDB with a preset of parameters"
	@echo "Make fclean \t deletes everything the makefile created"
	@echo "Make kitty \t prints a lil kitty on the terminal"
	@echo "Make leaks \t runs push_swap with valgrind -s --leak-check=full"
	@echo "Make re \t deletes all objects & dependencies and recompiles everything"
	@echo "Make run \t makes and runs push_swap with a preset of parameters"
	@echo "Make seg \t runs push_swap with valgrind"


kitty:
	@echo "   |\__/,|   ( \  "
	@echo " _.|o o  |_   ) ) "
	@echo "-(((---(((--------"

.PHONY : clean fclean all re run seg leaks debug help kitty dup invalid display
FORCE : 