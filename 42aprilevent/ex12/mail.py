from smtplib import SMTP
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
from email.mime.application import MIMEApplication

message = MIMEMultipart()
message['Subject'] = input("Title: ")
message.attach(MIMEText(input("Text: ")))

mailAdress = "istanbul42bot@gmail.com"
password = "juxf nxzf mysz anws"

sendTo = input("Mail adress: ")

filename = input("File name: ")
index = filename.index(".")
filetype = filename[index + 1:]

attachment = open(filename, "rb")
if attachment != None:
	part = MIMEApplication(attachment.read(), _subtype=filetype)
	part.add_header('Content-Disposition','attachment',filename=filename)
	message.attach(part)

mail = SMTP("smtp.gmail.com", 587)
mail.ehlo()
mail.starttls()
mail.login(mailAdress, password)
mail.sendmail(mailAdress, sendTo, message.as_string())
mail.quit()
