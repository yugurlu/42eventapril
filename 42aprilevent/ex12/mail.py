from smtplib import SMTP

subject = input("Title: ")
message = input("Message: ")
content = "Subject: {0}\n\n{1}".format(subject,message)

mailAdress = "your mail"
password = "google password"

sendTo = input("Mail adress: ")

mail = SMTP("smtp.gmail.com", 587)
mail.ehlo()
mail.starttls()
mail.login(mailAdress, password)
mail.sendmail(mailAdress, sendTo, content.encode("utf-8"))
