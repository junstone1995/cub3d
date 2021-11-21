첫번째 에러 -> void 반환인데 null 반환
src/main.c:32:3: error: void function 'cast_all_rays' should not return a value [-Wreturn-type]
                return (NULL);

두번째 에러 -> check_type은 static 임
src/parse1_utils.c:22:10: error: implicit declaration of function 'check_type' is invalid in C99 [-Werror,-Wimplicit-function-declaration]
                type = check_type(line);
                       ^
src/parse1_utils.c:24:4: error: void function 'process_except' should not return a value [-Wreturn-type]
                        return (exit_error(game, EXIT_FAILURE, "ERROR\nwrong type"));
                        ^      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
src/parse1_utils.c:25:7: error: implicit declaration of function 'is_blank_line' is invalid in C99 [-Werror,-Wimplicit-function-declaration]
                if (is_blank_line(line) && !(config->map))
                    ^
src/parse1_utils.c:31:4: error: void function 'process_except' should not return a value [-Wreturn-type]
                        return (exit_error(game, EXIT_FAILURE, "blank line in the map"));
                        ^      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
src/parse1_utils.c:33:4: error: void function 'process_except' should not return a value [-Wreturn-type]
                        return (0);
