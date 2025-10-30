print("Chatbot: Hi! I am a simple chatbot. How can I help you today?")

while True:
    user_input = input("You: ")
    if user_input.lower() == "hello":
        print("Chatbot: Hello! How are you?")
    elif user_input.lower() == "how are you?":
        print("Chatbot: I am just a program, but I’m doing well. Thank you!")
    elif user_input.lower() == "bye":
        print("Chatbot: Goodbye! Have a great day!")
        break
    else:
        print("Chatbot: Sorry, I don’t understand that.")
