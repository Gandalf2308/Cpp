contacts = {}
contacts["Bhoumish Grover"] = {"phone": "9876543210", "email": "bhoumish.grover@somaiya.edu"}
contacts["Baldhruva pogul"] = {"phone": "9123456789", "email": "baldhurva.pogul@somaiya.edu"}
contacts["Chaitya Doshi"] = {"phone": "9988776655", "email": "chaitya.doshi@somaiya.edu"}
contacts["Chaitanya Dhamdhere"] = {"phone": "8765432109", "email": "c.dhamdhere@somaiya.edu"}
print("Current Contacts:")
for name, info in contacts.items():
    print(f"Name: {name}, Phone: {info['phone']}, Email: {info['email']}")
# Using get() to retrieve a specific contact's email
contact_name = "Ayan Tripathi"
email = contacts.get(contact_name, {}).get('email', 'Not Found')
print(f"\nEmail of {contact_name}: {email}")
# Viewing all keys using keys()
print("\nAll Contact Names:")
print(list(contacts.keys()))
# Viewing all values using values()
print("\nAll Contact Details:")
print(list(contacts.values()))
# Updating a contact's email using setdefault()
contacts.setdefault("Baldhruva pogul", {})['email'] = "Baldhruva.pogul@somaiya.edu"
print("\nUpdated Baldhruva Pogul's email.")
# Deleting a contact using pop()
delete_info = contacts.pop("Chaitya Doshi", None)
if delete_info:
    print("\nDeleted Chaitya Doshi.")
else:
    print("\nChaitya Doshi not found.")
print("\nFinal Contacts:")
for name, info in contacts.items():
    print(f"Name: {name}, Phone: {info['phone']}, Email: {info['email']}")