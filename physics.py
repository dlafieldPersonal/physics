import pygame as pg
import random
import math
crashed = False

numOfParticalsStart = 30
epsilon = 2
gravConst = 1000.0

windowWidth = 1200
windowHeight = 600

keepFactor = 1.5
#keepFactor = 10000
initialMass = 1.0
shouldAimForCenter = True

black = (0, 0, 0)
blue = (0, 0, 255)
green = (0, 255, 0)
aqua = (0, 255, 255)
red = (255, 0, 0)
purple = (255, 0, 255)
yellow = (255, 255, 0)
white = (255, 255, 255)

listOfColors = [black, blue, green, aqua, red, purple, yellow, white]

particals = []

def distance(x1, y1, x2, y2):
	return ((x1 - x2) ** 2 + (y1 - y2) ** 2) ** 0.5

def plot(ds, color, x, y):
	pg.draw.line(ds, color, [x, y], [x, y], 1)
	
def updateGravity(lstOfParticals):
	
	#print("start of update grav")
	#(color, mass, x, y, dx, dy, accX, accY) = pp
	for i in range(len(lstOfParticals)):
		(iCol, iMass, iX, iY, iDx, iDy, iAccX, iAccY) = lstOfParticals[i]
		xGrav = 0.0
		yGrav = 0.0
		for j in range(len(lstOfParticals)):
			if i != j:
				(jCol, jMass, jX, jY, jDx, jDy, jAccX, jAccY) = lstOfParticals[j]
				r2 = (iX - jX) ** 2 + (iY - jY)**2
				"""
				if r2 < epsilon:
					print("Particle i = " + str(lstOfParticals[i]))
					print("Particle j = " + str(lstOfParticals[j]))
					print("iX = " + str(iX))
					print("iY = " + str(iY))
					print("jX = " + str(jX))
					print("jY = " + str(jY))
					print("diffX = " + str((iX - jX)))
					print("diffY = " + str((iY - jY)))
					print("r2 = " + str(r2))
					continue
					
				print("Particle i = " + str(lstOfParticals[i]))
				print("Particle j = " + str(lstOfParticals[j]))
				print("iX = " + str(iX))
				print("iY = " + str(iY))
				print("jX = " + str(jX))
				print("jY = " + str(jY))
				print("diffX = " + str((iX - jX)))
				print("diffY = " + str((iY - jY)))
				print("r2 = " + str(r2))
				"""
				gravAcc = iMass * jMass * gravConst / r2
				#print("gravAcc = " + str(gravAcc))
				dist = r2 ** 0.5
				#print("dist = " + str(dist))
				###
				gravDone = False
				#if same x, only do y
				if dist < epsilon:
					if abs(iX - jX) < epsilon:
						gravDone = True
						if jY > iY:
							yGrav += gravAcc
						else:
							yGrav -= gravAcc
						#print("theta = Infinity")
					if abs(iY - jY) < epsilon:
						gravDone = True
						if jX > iX:
							xGrav += gravAcc
						else:
							xGrav -= gravAcc
						#print("theta = 0")
					if not gravDone:
						theta = math.atan((iY - jY) / (iX - jX))
						#print("theta = " + str(theta))
						if jX > iX:
							xGrav += gravAcc * math.cos(theta)
						else:
							xGrav -= gravAcc * math.cos(theta)
						if jY > iY:
							yGrav += gravAcc * math.sin(theta)
						else:
							yGrav -= gravAcc * math.sin(theta)
		lstOfParticals[i] = (iCol, iMass, iX, iY, iDx, iDy, xGrav, yGrav)
	#print("end of update grav")
	
def initializeParticals(numOfParticals=1):
	#create white particals in random place
	#each partical has color, x, and y along with vel and acc 
	
	for i in range(numOfParticals):
		#xLoc = random.randrange(windowWidth)
		xLoc = random.uniform(0.0, 0.0 + windowWidth)
		#xLoc = windowWidth / 2.0
		#yLoc = random.randrange(windowHeight)
		yLoc = random.uniform(0.0, 0.0 + windowHeight)
		#yLoc = windowHeight / 2.0
		"""
		dx = 1
		dy = -1
		"""
		
		dx = 0
		#while dx == 0:
		#	dx = random.uniform(-1.0, 1.0)
		dy = 0
		#while dy == 0:
		#	dy = random.uniform(-1.0, 1.0)
		
		"""
		accX = 1
		accY = -1
		"""
		
		accX = random.uniform(-1.0, 1.0)
		#accX += 0.1
		accY = random.uniform(-1.0, 1.0)
		#accY += 0.1
		if shouldAimForCenter:
			if xLoc > windowWidth / 2:
				accX = random.uniform(-0.10, 0.0)
			else:
				accX = random.uniform(0.0, 0.10)
			if yLoc > windowHeight / 2:
				accY = random.uniform(-0.10, 0.0)
			else:
				accY = random.uniform(0.0, 0.10)
		curColor = random.choice(listOfColors)
		while curColor == black:
			curColor = random.choice(listOfColors)
		#curColor = white
		#particals.append((curColor, initialMass, xLoc, yLoc, dx, dy, accX, accY))
		particals.append((curColor, initialMass, xLoc, yLoc, dx, dy, 0.0, 0.0))
		
def drawParticals(ds):
	
	finished = True
	for pp in particals:
		(color, mass, x, y, dx, dy, accX, accY) = pp
		if int(x) in range(windowWidth) and int(y) in range(windowHeight):
			finished = False
			#plot(ds, color, int(x), int(y))
			i = 0
			while i < mass ** 0.5:
				j = 0
				while j < mass ** 0.5:
					plot(ds, color, int(x + i), int(y + j))
					j += 1
				i += 1
	return finished
	
def combine():
	i = 0
	collided = True
	while collided:
		collided = False
		while i < len(particals):
			(iColor, iMass, ix, iy, idx, idy, iAccX, iAccY) = particals[i]
			if abs(ix) > keepFactor * windowWidth or abs(iy) > keepFactor * windowHeight:
				collided = True
				del particals[i]
				break
			j = i + 1
			while j < len(particals):
				
				(jColor, jMass, jx, jy, jdx, jdy, jAccX, jAccY) = particals[j]
				if distance(ix, iy, jx, jy) < (iMass + jMass) ** 0.5 / 2:
					collided = True
				#if collided, combine 2 particals into new partical, remove old particals, and add new particals, then break
				if collided:
					newPartical = (iColor, iMass + jMass, (ix + jx) / 2, (iy + jy) / 2, (idx + jdx) / 2, (idy + jdy) / 2, (iAccX + jAccX) / 2, (iAccY + jAccY) / 2)
					del particals[j]
					del particals[i]
					particals.append(newPartical)
					break
				j += 1
			if collided:
				break
			i += 1

def updateParticals():
	
	#print("Start of update particals")
	
	combine()	
	for pIndex in range(len(particals)):
		(curColor, mass, x, y, dx, dy, accX, accY) = particals[pIndex]
		
		#twinkle
		#curColor = random.choice(listOfColors)
		
		updateGravity(particals)
		
		#change speed based on accelleration
		dx += accX
		dy += accY
		
		#move based on speed
		x += dx
		y += dy
		particals[pIndex] = (curColor, mass, x, y, dx, dy, accX, accY)
	#print("end of update particals")
		
initializeParticals(numOfParticalsStart)

pg.init()
gameDisplay = pg.display.set_mode((windowWidth, windowHeight))
pg.display.set_caption("gravity window")
clock = pg.time.Clock()

finished = False
for p in particals:
	print(p)
print("\n\n\n")
breakTime = 3
while not crashed and not finished and breakTime > 0:
	#breakTime -= 1
	for event in pg.event.get():
		if event.type == pg.QUIT:
			crashed = True
	updateParticals()
	print(str(len(particals)) + " particals")
	"""
	for p in particals:
		print(p)
	"""
	#pg.draw.rectangle(gameDisplay, 0, 0, windowHeight, windowWidth)
	gameDisplay.fill(black)
	finished = drawParticals(gameDisplay)
	pg.display.update()
	clock.tick(60)
	
pg.quit()

print("Done.")
quit()
