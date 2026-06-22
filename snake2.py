import pygame
import random
import button
pygame.mixer.init()


pygame.init()
white = (255,255,255)
red = (255,0,0)
black = (0,0,0)
green = (150,255,0)
brown= (165,42,42)
blue = (140,190,214)


screen_width = 900
screen_height = 600
gamewindow=pygame.display.set_mode((screen_width,screen_height))

bgimg = pygame.image.load("sna2.jpg")
bgimg = pygame.transform.scale(bgimg,(screen_width,screen_height)).convert_alpha()
end = pygame.image.load("game over.jpg")
end = pygame.transform.scale(end,(screen_width,screen_height)).convert_alpha()
strt = pygame.image.load("start.jpg")
strt = pygame.transform.scale(strt,(screen_width,screen_height)).convert_alpha()
strt_img = pygame.image.load("s1.png").convert_alpha()
exit = pygame.image.load("exit game1.jpg").convert_alpha()
strt_new = pygame.image.load("1 new.png").convert_alpha()
home = pygame.image.load("home1.png").convert_alpha()



pygame.display.set_caption("snack")

pygame.display.update()    #kai pan add krya pachi update karvu jaroori che


clock = pygame.time.Clock()
font = pygame.font.SysFont(None,25,bold=False,italic=True)
font2 = pygame.font.SysFont(None,45,italic=True)
font3 = pygame.font.SysFont(None,45,italic=False)

def t_screen(text,color,x,y):  #score screen lavva
     screen_text = font.render(text,True,color)
     gamewindow.blit(screen_text,[x,y])
def m_screen(text,color,x,y):  #score screen lavva
     screen_text = font2.render(text,True,color)
     gamewindow.blit(screen_text,[x,y])
def b_screen(text,color,x,y):  #score screen lavva
     screen_text = font3.render(text,True,color)
     gamewindow.blit(screen_text,[x,y])


     
     
def plot_snake(gamewindow,color,snk_list,snake_size):
    for x,y in snk_list:
 
      pygame.draw.circle(gamewindow,color,(x,y),20)
def welcome():
    exit_game = False
    while not exit_game:
        gamewindow.fill(white)
        gamewindow.blit(strt,(0,0))
        pygame.draw.line(gamewindow,white,[0,0],[1000,0],20)
        pygame.draw.line(gamewindow,white,[0,0],[0,1000],20)
        pygame.draw.line(gamewindow,white,[0,600],[1000,600],20)
        pygame.draw.line(gamewindow,white,[900,0],[900,1000],20)

        
        strt_button = button.Button(400,400,strt_img,1)
        if (strt_button.draw(gamewindow)):
            pygame.mixer.music.load("snake.mp3")
            pygame.mixer.music.play()
            gameloop()
      
        t_screen("PRESS START BUTTON ",white,370,460)
       
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                exit_game = True
            if event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_SPACE:
                        pygame.mixer.music.load("snake.mp3")
                        pygame.mixer.music.play()
                        gameloop()
                   
        pygame.display.update()
        clock.tick(60)
           
               
        
#game loop
def gameloop():
    exit_game = False
    game_over = False
    snake_x=45
    snake_y = 55
    snake_size = 40
    fps = 60
    valocity_x = 0
    valocity_y = 0
    snk_list = []
    snk_length = 1
    with open ("highscore.txt","r") as f:
      highscore = f.read()
    
    
    food_x = random.randint(150,850)
    food_y = random.randint(150,300)
    
    score = 0
    speed = 2
    while not exit_game:
        if game_over:
            
            
            with open ("highscore.txt","w") as f:
                 f.write(str(highscore))
                 
            gamewindow.fill(white)
            gamewindow.blit(end,(0,0))
            pygame.draw.line(gamewindow,blue,[0,0],[1000,0],20)
            pygame.draw.line(gamewindow,blue,[0,0],[0,1000],20)
            pygame.draw.line(gamewindow,blue,[0,600],[1000,600],20)
            pygame.draw.line(gamewindow,blue,[900,0],[900,1000],20)
            m_screen("  Highscore :"+str(highscore),blue,15,25)
            exit_image = button.Button(150,400,exit,1/2)
            new_game  = button.Button(350,100,strt_new,1.2)
            home_game = button.Button(500,400,home,0.85)
            
            if(exit_image.draw(gamewindow)):
                exit_game = True
            elif(new_game.draw(gamewindow)):
                pygame.mixer.music.load("snake.mp3")
                pygame.mixer.music.play()
                gameloop()
            elif(home_game.draw(gamewindow)):
                welcome()
           
            
            for event in pygame.event.get():    
                # print(event) 
                if event.type == pygame.KEYDOWN:
                    if event.type == pygame.K_e: 
                        exit_game = True
               
                if event.type == pygame.QUIT:
                   exit_game = True
               
            if event.type == pygame.KEYDOWN:
                   
                if event.key == pygame.K_RETURN:
                        pygame.mixer.music.load("snake.mp3")
                        pygame.mixer.music.play()
                
                    
                    
                        gameloop()
        else:
            for event in pygame.event.get():
                # print(event) 
                if event.type == pygame.QUIT:
                   exit_game = True
                
                
                if event.type==pygame.KEYDOWN:
                    if event.key==pygame.K_RIGHT or event.key == pygame.K_d:
                        # snake_x=snake_x+10
                        valocity_x =speed
                        valocity_y = 0
                    if event.key==pygame.K_DOWN or event.key == pygame.K_s:
                        # snake_y=snake_y+10
                        valocity_y =speed
                        valocity_x  = 0
                    if event.key==pygame.K_LEFT or event.key == pygame.K_a:
                        # snake_x=snake_x-10
                        valocity_x = -speed
                        valocity_y = 0
                    if event.key==pygame.K_UP or event.key == pygame.K_w:
                        # snake_y=snake_y-10  
                        valocity_y = -speed
                        valocity_x = 0
                    if event.key == pygame.K_q:
                        exit_game = True
                        
            snake_x = snake_x + valocity_x
            snake_y = snake_y + valocity_y

            if abs(snake_x-food_x)<40 and abs(snake_y-food_y)<40:
                score+=10
                # print("score :",score)
                food_x = random.randint(50,400)
                food_y = random.randint(50,300)
                snk_length += 6
               
            
                if score>int(highscore):
                    highscore = score
                      
            gamewindow.fill(green)
            gamewindow.blit(bgimg,(0,0))
            pygame.draw.line(gamewindow,red,[0,0],[1000,0],20)
            pygame.draw.line(gamewindow,red,[0,0],[0,1000],20)
            pygame.draw.line(gamewindow,red,[0,600],[1000,600],20)
            pygame.draw.line(gamewindow,red,[900,0],[900,1000],20)
            
            b_screen("_____________ ",white,15,-8)
            b_screen("|",white,232,18)
            b_screen("|",white,11,18)
            b_screen("_____________ ",white,15 ,20)
            t_screen("score :"+str(score)+ "  Highscore :"+str(highscore),red,20,25)
            pygame.draw.circle(gamewindow,red,[food_x,food_y],20)
            # pygame.draw.rect(gamewindow,black, [snake_x,snake_y,snake_size,snake_size])
            
            
            head = []
            head.append(snake_x)
            head.append(snake_y)
            snk_list.append(head)
            
            if len(snk_list)>snk_length:
                del snk_list[0]
            
            if head in snk_list[:-1]:
                game_over = True
                pygame.mixer.music.load("gameover.mp3")
                pygame.mixer.music.play()
                # pygame.mixer.music.stop()
                
            
            if snake_x<0 or snake_x>900 or snake_y<0 or snake_y>600:
                game_over = True
                pygame.mixer.music.load("gameover.mp3")
                pygame.mixer.music.play()
                # pygame.mixer.music.stop()
                
            
            
            plot_snake(gamewindow,white,snk_list,snake_size)
        pygame.display.update()
        clock.tick(fps)
    pygame.quit()
    quit()

welcome()

