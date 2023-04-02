import json
import requests

pokemon_name = input("Enter the name of a Pokemon: ").lower()
data = requests.get("https://pokeapi.co/api/v2/pokemon/" + pokemon_name)

if data.status_code != 200:
	print("Error: Unable to retrieve data.")
	exit()

data = data.json()

print("Name:", data["name"].capitalize())
print("Abilities:")
for ability in data["abilities"]:
	print("-", ability["ability"]["name"].capitalize())
