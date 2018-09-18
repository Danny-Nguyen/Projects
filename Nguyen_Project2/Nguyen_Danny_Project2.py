from random import randint #the library imported is random and it creates a random integer to use for the battle scores

class Leagues: # this class creates a dictionary and adds different lists as values in order to make it a complex object. 
	def __init__(self):# this default constructor reads from three different files and adds in the keys and values into the dictionary from the league champs.txt file.
		self.champions = open("League Champs.txt", 'r')
		self.rift = {}
		self.adap = open("adap.txt", 'r')
		self.roles = open("roles.txt", 'r')
		for i in self.champions:
			data = i.strip()
			data = data.split()
			self.rift[int(data[0])] = []
			self.rift[int(data[0])].append(data[1])
		
	def Teamcomp(self): # this function appends the information from the adap.txt file into a value for the dictionary under each champion. 
		damage = 1
		for i in self.adap:
			comp = i.strip()
			self.rift[damage].append(comp)
			damage += 1
		return self.rift
		
	def Teamroles(self): # this function appends the information from the roles.txt file into a value for the dictionary under each champion. 
		lane = 1
		for i in self.roles:
			roles = i.strip()
			self.rift[lane].append(roles)
			lane += 1
		return self.rift
	
	def printchampions(self): # this function prints out all keys and values from the dictionary 
		print self.rift
		
class Game(Leagues): # this class inherits the leagues class and uses data from the dictionary in order to make the league simulator function. 
	def __init__(self):
		Leagues.__init__(self)
		self.totalcomp = []
		self.newcomp = []
		self.nexushealth = 250
		
	def chooseteam(self): # the main purpose of this function is to print out only the names of each champion and then allow the user to choose 5 based on their input. A list of champions chosen is then created and stored in a new .txt file to be used. 
		for numbers in range(1, 103):
			numbernum = self.rift[numbers]
			self.totalcomp.append(numbernum)
		for i in self.totalcomp:
			print i[0]
		for x in range(0, 5):
			choice = raw_input("Please select a champion from the list .\n")
			try:
				if choice not in self.totalcomp:
					self.newcomp.append(choice)
					print "\n This is your team.\n", self.newcomp, "\n"
			except:
				print "Champion does not exist"
	def randombattle(self): # this function gives each value of the list a random int value from 1 to 100 and uses it as their battle power. It then sums the different values and if it exceeds the nexushealth, then the user wins the game. It also gives the champion a name based on the score they received. 
		with open("Teams.txt", 'w') as newfile:
			for i in self.newcomp:
				newfile.write(i)
		with open("Teams.txt", 'r') as openfile:
			rando = 0
			for i in self.newcomp:
				randomnumber = randint(1, 100)
				print i, "Given Attack Power: ", randomnumber
				if randomnumber > 0 and randomnumber <= 20:
					print "Feeder"
				elif randomnumber > 20 and randomnumber <= 40:
					print "Not Bad"
				elif randomnumber > 40 and randomnumber <= 60:
					print "Decent"
				elif randomnumber > 60 and randomnumber <= 80:
					print "Carrier"
				elif randomnumber >80 and randomnumber <= 100:
					print "Faker"
				rando += randomnumber
			print "\n Total Team Power: ", rando
		if rando >= self.nexushealth:
			print "\n Victory!"
		elif rando <= self.nexushealth:
			print "\n Defeat!"
			
def main(): # the main function sets up many while loops in order to ask the user what they'd like to to do. 
	
	league = Leagues()
	league.Teamcomp()
	league.Teamroles()
	s = 0
	while s == 0:
		answer3 = raw_input("Would you like to view the current champions? (y/n)\n")
		if answer3 == "y":
			s = 1
			league.printchampions()
		elif answer3 == "n":
			s = 1
		else:
			print "Please enter a valid answer."
			
	x = 0
	while x == 0:
		answer = raw_input("Would you like to play a game of League of Legends? (y/n)\n")
		if answer == "y":
			leagueteam = Game()
			leagueteam.chooseteam()
			leagueteam.randombattle()
			an = 0
			while an == 0:
				answer2 = raw_input("Would you like to play again?\n")
				if answer2 == "y":
					leagueteam = Game()
					leagueteam.chooseteam()
					leagueteam.randombattle()
				elif answer2 == "n":
					an = 1
					print "Good-bye!"
					exit()
				else:
					print "Please enter a valid response.\n"
		elif answer == "n":
			x = 1
			print "Good-bye!"
		else:
			print "Please enter a valid answer.\n"
			
main()
