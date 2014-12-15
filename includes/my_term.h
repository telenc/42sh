/*
** my_term.h for my_term in /home/telenc_r/rendu/42sh/my
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Wed May 22 12:16:41 2013 telenc_r
** Last update Sun May 26 15:52:05 2013 telenc_r
*/

#ifndef MY_TERM_H_
# define MY_TERM_H_

#define	QUIT	buff[0] == 27 && buff[1] == 0
#define	DELETE	buff[0] == 127 && buff[1] == 0
#define	ARROW	(buff[0] == 27 && buff[1] == 91)
#define	ARROW_L ARROW && buff[2] == 68
#define	ARROW_R ARROW && buff[2] == 67
#define	ARROW_U ARROW && buff[2] == 65
#define	ARROW_D ARROW && buff[2] == 66
#define	ENTER	buff[0] == 10 && buff[1] == 0
#define	TAB	buff[0] == 9 && buff[1] == 0
#define	CLEAR	buff[0] == 12 && buff[1] == 0
#define	CTRL_F	buff[0] == 6 && buff[1] == 0
#define	CTRL_A	buff[0] == 1 && buff[1] == 0
#define	CTRL_U	buff[0] == 21 && buff[1] == 0
#define	CTRL_P	buff[0] == 16 && buff[1] == 0
#define	CTRL_H	buff[0] == 8 && buff[1] == 0
#define	CTRL_C	buff[0] == 3 && buff[1] == 0
#define	CTRL_D	buff[0] == 4 && buff[1] == 0

#endif /* !MY_TERM_H_ */
