typedef char* string;

struct contactPerson{
	string contact_person_id;
	string first_name;
	string last_name;
	string email;
};

struct contact{
	string contact_id;
	string contact_name;
	string contact_street;
	string area;
	struct *contactPerson;
} *contacts;