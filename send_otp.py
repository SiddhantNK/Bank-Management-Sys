from email.message import EmailMessage
import smtplib
import random
import sys
import os

f = open("temp.txt")
user_mail = f.read()
f.close()

otp = random.randint(1000,9999)

f2 = open("temp.txt", "w")
f2.write(str(otp))
f2.close()

sender_email = "fahim.1251050258@vit.edu"
password = "nfvz ctep sasw tili"
reciever_email = user_mail

print()

message = EmailMessage()

message["From"] = sender_email
message["To"] = reciever_email
message["Subject"] = "OTP for Laxmi Chit Bank Fund Login"
message.set_content(f"Your OTP for Laxmi Chit Bank Fund Login is: {otp}")

try:
  with smtplib.SMTP_SSL("smtp.gmail.com", 465) as server:
    server.login(sender_email, password)
    server.send_message(message)
    server.quit()
    print(0)
except:
  print("not able to send")

# userOtp = int(input("Enter the OTP: "))

# print("\033c", end="")  # Clear the screen for clean output

# if (otp == userOtp):
#   print("OTP Verified.")
#   sys.exit(0)
#   # os.system('cls')
# else:
#   print("Wrong OTP, Please try again.")
#   sys.exit(1)