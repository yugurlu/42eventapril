from smtplib import SMTP
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
from email.mime.application import MIMEApplication

message = MIMEMultipart()
message['Subject'] = input("Title: ")
message.attach(MIMEText(input("Text: ")))

mailAdress = "your_mail"
password = "your_password"

sendTo = input("Mail adress: ")

filename = input("File name: ")
index = filename.index(".")
filetype = filename[index + 1:]

with open(filename, "rb") as attachment:
	part = MIMEApplication(attachment.read(), _subtype=filetype)
	part.add_header('Content-Disposition','attachment',filename=filename)
	message.attach(part)

mail = SMTP("smtp.gmail.com", 587)
mail.ehlo()
mail.starttls()
mail.login(mailAdress, password)
mail.sendmail(mailAdress, sendTo, message.as_string())
mail.quit()
