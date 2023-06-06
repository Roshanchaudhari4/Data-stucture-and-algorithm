#Consider telephone book database of N clients. Make use of a hash table 
#implementation to quickly look up client‘s telephone number. Make use of any 
#collisionhandling techniques. Operations- 1. Insert 2. Search 3. Display








class ClientEntry:
    def __init__(self, name, phone_number):
        self.name = name
        self.phone_number = phone_number
        
class HashTable:
    def __init__(self, size):
        self.size = size
        self.buckets = [None] * size

    def hash_function(self, key):
        # Choose a suitable hash function based on your requirements
        # Example: Simple modulo hashing
        return hash(key) % self.size

    def insert(self, name, phone_number):
        index = self.hash_function(name)
        entry = ClientEntry(name, phone_number)

        if self.buckets[index] is None:
            self.buckets[index] = [entry]
        else:
            self.buckets[index].append(entry)

    def search(self, name):
        index = self.hash_function(name)

        if self.buckets[index] is not None:
            for entry in self.buckets[index]:
                if entry.name == name:
                    return entry.phone_number

        return None

    def display(self):
        for i in range(self.size):
            if self.buckets[i] is not None:
                for entry in self.buckets[i]:
                    print(f"Name: {entry.name}, Phone Number: {entry.phone_number}")
# Create a hash table
hash_table = HashTable(100)

# Insert entries
hash_table.insert("John Doe", "1234567890")
hash_table.insert("Jane Smith", "9876543210")
hash_table.insert("Alice Johnson", "5555555555")

# Search for a phone number
phone_number = hash_table.search("Jane Smith")
if phone_number is not None:
    print(f"Phone number: {phone_number}")
else:
    print("Name not found.")

# Display all entries
hash_table.display()
