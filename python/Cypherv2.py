import cypherlist
import keyfile

print("|          Cypherv2.py            |\n"
      "|Encryption method developed by   |\n"
      "|SethSands.                       |\n"
      "|1 - Encode                       |\n"
      "|2 - Decode                       |\n"
      "|[any other text] - Quit          |\n")
print("Current ciphers: Rome ; b16 ; Gambit ; tesseract ; 3dsect")
while True:
    z=input("Enter choice of Operation: ")
    if z=="1":
        og=input("Enter string to encode:")
        cypherlist.encychoice(og)
    elif z=="2":
        og=input("Enter string to decode:")
        keyfile.decychoice(og)
    else:
        print("Quitting...")
        break
        
    


