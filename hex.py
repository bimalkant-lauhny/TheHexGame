import pygame
from pygame.locals import *
import os, sys
from math import cos, sin

#Constants
HEIGHT = 400
WIDTH = 300
left = 40
top = 50
width = 30
height = 30
black = (0,0,0)
white = (250, 250, 250)
red = (250, 0, 0)
blue = (0, 0, 255)

def returnnr(index):
    if(index <= 21):
        for i in range(7):
            if(i*(i+1)/2 >= index):
                x = i-1
                y = index - x*(x+1)/2
                return x+1, y
    else:
        myval = index - 21
        ty = 5
        cou = 1
        while(myval - ty > 0):
            myval = myval - ty
            ty -= 1
            cou += 1
        return 6+cou, myval
            


class Hexagon(object):
    '''Draw a hexagon in the canvas given its start point. That is the upper point in the hexagon'''
    def __init__(self, x, y):
        self.colorfill = white
        self.side = 16
        self.color = (0,0,0)
        self.points = []
        self.x = x
        self.updated = False
        theta = 30/57.29577951308232;
        self.y = y
        self.index = 0
        self.rect = pygame.Rect((self.x - self.side*cos(theta), self.y + self.side*sin(theta)), (self.side, 2*cos(theta)*self.side))
    def returnPoints(self):
        points = []
        theta = 30/57.29577951308232;
        points.append((self.x, self.y))
        points.append((self.x - self.side*cos(theta), self.y + self.side*sin(theta)))
        points.append((self.x - self.side*cos(theta), self.y + self.side*sin(theta) + self.side))
        points.append((self.x, self.y + 2*self.side*sin(theta) + self.side))
        points.append((self.x + self.side*cos(theta), self.y + self.side*sin(theta) + self.side))
        points.append((self.x + self.side*cos(theta), self.y + self.side*sin(theta)))
        return points
    
    def update(self,x,y,p):
        c = self.rect.collidepoint(x, y)
        if(c):
            if(p):
                self.color = blue
                self.updated = True
                myx, myy = returnnr(self.index)
                with open('guiout','w') as fp:
                    fp.write(str(myx))
                    fp.write('\n')
                    fp.write(str(int(myy)))
        return
    def returnColor(self):
        return self.color
    def returnUpdate(self):
        return self.updated


    def make_polygon(self, points, action=None):
        c = pygame.draw.polygon(screen,self.color,a,3);
def main():
    pygame.init()
    screen = pygame.display.set_mode((700, 700))
    pygame.display.set_caption("HEX")

    background = pygame.Surface(screen.get_size())
    another_screen = pygame.Surface((350, 700))
    background = background.convert()
    another_screen.fill((250,250,250))
    background.fill((250,250, 250))
    screen.blit(background, (0, 0))
    clock = pygame.time.Clock()
    gameon = True
    a = Hexagon(350, 50)
    points = a.returnPoints()
    listPoints = []
    listPoints.append(points[0])
    generPoint = points[2]
    secondPoint = 3
    goi= [points[0], points[1], points[2]]
    count = 2
    side = 16
    theta = 30/57.29577951308232;
    distance = 2*side*cos(theta)
    line1x = (320, 50)
    oo = [points[0], points[5], points[4]]
    for i in range(5):
        for j in range(count):
            listPoints.append((generPoint[0] + j*distance, generPoint[1]))
        a = Hexagon(listPoints[-count][0], listPoints[-count][1]).returnPoints()
        b = Hexagon(listPoints[-1][0], listPoints[-1][1]).returnPoints()
        he = a[1]
        oo.extend([b[5], b[4]])
        generPoint = a[2]
        goi.append(he)
        goi.append(generPoint)
        x = a[3]
        secondPoint = a[4]
        count+=1;
    del(goi[-1])
    count-=2
    generPoint = secondPoint
    p = [x]
    cd = []
    for i in range(5):
        for j in range(count):
            listPoints.append((generPoint[0] + j*distance, generPoint[1]))
        b = Hexagon(listPoints[-1][0], listPoints[-1][1]).returnPoints()
        a = Hexagon(listPoints[-count][0], listPoints[-count][1]).returnPoints()
        generPoint = a[4]
        ut = a[3]
        cd.extend([b[5], b[4]])
        p.extend([a[1], a[2]])
        count-=1
    del(goi[-1])
    del(oo[-1])
    del(oo[-1])
    p.append(ut)
    cd.append(ut)
    yo = []
    co = 1
    for point in listPoints:
        a = Hexagon(point[0], point[1])
        a.index = co
        co +=1
        yo.append(a)

    while(gameon):
        for event in pygame.event.get():
            if(event.type == pygame.QUIT):
                    pygame.quit()
                    quit()
        x, y = pygame.mouse.get_pos()
        click = pygame.event.wait().type == pygame.MOUSEBUTTONDOWN
        if(click):
            for hexa in yo:
                hexa.update(x, y, click)
        boardNow = ''
        for line in open("boardOutput").read():
            boardNow = boardNow + line.strip()
        for i in range(len(boardNow)):
            if(boardNow[i] == 'B'):
                yo[i].color = blue
                yo[i].updated = True
            elif(boardNow[i] == 'R'):
                yo[i].color = red
                yo[i].updated = True

        pygame.draw.lines(screen, red, False, goi, 6)
        pygame.draw.lines(screen, blue, False, oo, 6)
        pygame.draw.lines(screen, blue, False, p, 6)
        pygame.draw.lines(screen, red, False, cd, 6)
        for hexagon in yo:
            a = hexagon.returnPoints()
            b = hexagon.returnColor()
            c = hexagon.returnUpdate()
            if(c):
                pygame.draw.polygon(screen, b, a)
            else:
                pygame.draw.polygon(screen, b, a, 3)
            pygame.display.update()
        #screen.blit(another_screen, (154,0))
        clock.tick(5)
main()

