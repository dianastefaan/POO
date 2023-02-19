#include<iostream>
#include<string>
using namespace std;


class Utilizator {  //clasa abstracta
public:
	string username;
	string password;
	char* numeUtilizator;  // numele din buletin
	const int idUtilizator;
	static int contor;
	
	Utilizator() :idUtilizator(Utilizator::contor++) { //constr fara param
		this->username = "dadlles";
		this->password = "aprilie2";
		this->numeUtilizator = new char[strlen("Diana") + 1];
		strcpy_s(this->numeUtilizator, strlen("Diana") + 1, "Diana");
		
	}


	Utilizator(string username, string password, const char* numeUtilizator) :idUtilizator(Utilizator::contor++) //constructor cu toti parametrii
	
	{
		this->username = username;
		this->password = password;
		this->numeUtilizator = new char[strlen(numeUtilizator) + 1];
		strcpy_s(this->numeUtilizator, strlen(numeUtilizator) + 1, numeUtilizator);

	}

	Utilizator(const Utilizator&c) :idUtilizator(Utilizator::contor++) //constructorul de copiere

	{
		this->username = c.username;
		this->password = c.password;
		this->numeUtilizator = new char[strlen(c.numeUtilizator) + 1];
		strcpy_s(this->numeUtilizator, strlen(c.numeUtilizator) + 1, c.numeUtilizator);

	}



	Utilizator& operator= (const Utilizator& c) { //operator =
		if (this != &c) {

			delete[]this->numeUtilizator;
			this->username = c.username;
			this->password = c.password;
			this->numeUtilizator = new char[strlen(c.numeUtilizator) + 1];
			strcpy_s(this->numeUtilizator, strlen(c.numeUtilizator) + 1, c.numeUtilizator);


		}
		return *this;

	}


	//getteri
	string getUsername() {
		return this->username;
	}

	string getPassword() {
		return this->password;
	}

	char* getNumeUtilizator() {
		return this->numeUtilizator;
	}

	//setteri
	void setUsername(string username) {
		this->username = username;
	}

	void setPassword(string password) {
		this->password = password;
	}

	void setNumeUtilizator(const char* numeUtilizator) {

		if (strlen(numeUtilizator) > 2) {
			delete[]this->numeUtilizator;
		}
		this->numeUtilizator=new char[strlen(numeUtilizator) + 1];
		strcpy_s(this->numeUtilizator, strlen(numeUtilizator) + 1, numeUtilizator);
	}

	//op <<
	friend ostream& operator<<(ostream& out, const Utilizator& c) {

		out << "username:" << c.username << endl;
		out << "password:" << c.password << endl;
		out << "numele utilizatorului: " << c.numeUtilizator << endl;
		return out;
	}

	//op>>
	friend istream& operator>>(istream& in, Utilizator& c) {


		//string citire
		cout << "username: ";
		char buffer[200];
		in.getline(buffer, 200); 
		c.setUsername(buffer);

		cout << "password: ";
		in.getline(buffer, 200);
		c.setPassword(buffer);

		// char* citire 
		cout << "numele utilizatorului: ";
		in.getline(buffer, 200);
		delete[] c.numeUtilizator;

		c.numeUtilizator = new char[strlen(buffer) + 1];
		strcpy_s(c.numeUtilizator, strlen(buffer) + 1, buffer);


	}


	~Utilizator() {//destructor pt a dezaloca memorie
		
		if (this->numeUtilizator != NULL) {
			delete[]this->numeUtilizator;
		}

	}

	virtual void Test() = 0; //fct virtuala
};

int Utilizator::contor = 0;



class ProfilUtilizator :public Utilizator { //is a, mostenirea; o mosteneste pe cls abstracta
private:

	string email;
	int varsta;
	int nrPrieteni;
	string* prieteni;

	const int CODUnic;
	static int contorCOD;

public:
	
	void Test() { //fct virtuala
		cout << "Buna <3 ";
	}


	ProfilUtilizator():CODUnic(ProfilUtilizator::contorCOD++), Utilizator() //constr fara param
	{

		this->email = "ana.maria@gmail.com";
		this->varsta = 20;
		this->nrPrieteni = 4;
		this->prieteni = new string[nrPrieteni];
		this->prieteni[0] = "Costel";
		this->prieteni[1] = "Leana";
		this->prieteni[2] = "Vasile";
		this->prieteni[3] = "Mariuca";

	}


	ProfilUtilizator(string username,string password,const char* numeUtilizator,string email,int varsta,int nrPrieteni,string* prieteni)
		:CODUnic(ProfilUtilizator::contorCOD++), Utilizator( username,  password , numeUtilizator)  //constr cu toti param
	{
		this->email = email;
		this->varsta = varsta;
		this->nrPrieteni = nrPrieteni;
		this->prieteni = new string[nrPrieteni];
		for (int i = 0; i < nrPrieteni; i++) {
			this->prieteni[i] = prieteni[i];
		}


	}


	ProfilUtilizator(const ProfilUtilizator& c) :CODUnic(ProfilUtilizator::contorCOD++), Utilizator(c)//constr de copiere
	{
		this->email = c.email;
		this->varsta = c.varsta;
		this->nrPrieteni = c.nrPrieteni;
		this->prieteni = new string[c.nrPrieteni];
		for (int i = 0; i < c.nrPrieteni; i++) 
		{
			this->prieteni[i] = c.prieteni[i];
		}

	}


	ProfilUtilizator operator=(const ProfilUtilizator& c) //operator =
	{
		Utilizator::operator=(c);
		if (this != &c) {

			delete[]this->prieteni;

			this->email = c.email;
			this->varsta = c.varsta;
			this->nrPrieteni = c.nrPrieteni;
			this->prieteni = new string[c.nrPrieteni];
			for (int i = 0; i < c.nrPrieteni; i++)
			{
				this->prieteni[i] = c.prieteni[i];
			}


		}
		return *this;
	}


	//getteri
	string getEmail()
	{
		return this->email;
	}

	int getVarsta()
	{
		return this->varsta;
	}

	int getnrPrieteneni()
	{
		return this->nrPrieteni;
	}

	string* getPrieteni()
	{
		return this->prieteni;
	}

	
	//setteri
	void setEmail(string email)
	{
		this->email = email;
	}

	void setVarsta(int varsta)
	{
		this->varsta = varsta;
	}


	void setnrPrieteni(int nrPrieteni)
	{
		this->nrPrieteni = nrPrieteni;
	}


	void setPrieteni(int nrPrieteni, string* prieteni)
	{
		if (this->prieteni != NULL) {
			delete[]this->prieteni;
		}
		this->nrPrieteni = nrPrieteni;

		this->prieteni = new string[nrPrieteni];
		for (int i = 0; i < nrPrieteni; i++)
		{
			this->prieteni[i] = prieteni[i];
		}
		
	}


	friend ostream& operator<< (ostream& out, const ProfilUtilizator& c) //op <<
	{
		out << (Utilizator&)c << endl;
		out << "email: " << c.email << endl;
		out << "varsta: " << c.varsta << endl;
		out << "nr prieteni: " << c.nrPrieteni << endl;
		for (int i = 0; i < c.nrPrieteni; i++)
		{
			out << "prieteni: " << c.prieteni << endl;
		}

		return out;
	}



	friend istream& operator>> (istream& in, ProfilUtilizator& c) //op >>
	{
		cout << "email: ";
		in >> c.email;

		cout << "varsta: ";
		in >> c.varsta;

		cout << "numar de prieteni: ";
		in >> c.nrPrieteni;

		delete[]c.prieteni;
		c.prieteni = new string[c.nrPrieteni];
		for (int i = 0; i < c.nrPrieteni; i++) {
			cout << "prietenii sunt: " << i + 1;
			in >> c.prieteni[i];
		}


		return in;

	}

//operator -- preincr
	ProfilUtilizator& operator--() {
		this->nrPrieteni--;
		return *this;
	}
//operator -- postincr
	ProfilUtilizator& operator--(int) {
		this->nrPrieteni--;
		return *this;
	}

//operator ++ preincr
	 ProfilUtilizator& operator++() {
		this->nrPrieteni++;
		return *this;
	}

//operator ++ postincr
	ProfilUtilizator& operator++(int) {
		this->nrPrieteni++;
		return *this;
	}

//operator += 
	ProfilUtilizator& operator+=(int nrPrieteni)
	{
		this->nrPrieteni += nrPrieteni;
		return *this;
	}


	~ProfilUtilizator() {//destructor
		if (this->prieteni != NULL) {
			delete[]this->prieteni;
		}
	}

};

int ProfilUtilizator::contorCOD = 0;


class ProfilCelebru :public ProfilUtilizator //mostenire clasa profil utilizator
{
private:

	float numarUrmaritori;
	int numarPostari;
	int* numarLikes;
	string AppSocialMedia;
	

public:


	ProfilCelebru():ProfilUtilizator() 
	{
		this->numarUrmaritori = 30000;
		this->numarPostari = 3;
		this->numarLikes = new int[numarPostari];
		this->numarLikes[0] = 40000;
		this->numarLikes[1] = 100000;
		this->numarLikes[2] = 50000;
		this->AppSocialMedia = "instagram";


	}
		
	ProfilCelebru(string username, string password, const char* numeUtilizator, string email, int varsta, int nrPrieteni, string* prieteni,
		float numarUrmaritori, int numarPostari, int* numarLikes, string AppSocialMedia)
		:ProfilUtilizator (username,password,numeUtilizator,email,varsta,nrPrieteni,prieteni)
	{

		this->numarUrmaritori = numarUrmaritori;
		this->numarPostari = numarPostari;
		this->numarLikes = new int[numarPostari];
		for (int i = 0; i < numarPostari; i++) {
			this->numarLikes[i] = numarLikes[i];
		}
		this->AppSocialMedia = AppSocialMedia;

	}


	ProfilCelebru(const ProfilCelebru& c) :ProfilUtilizator(c) { //c de copiere

		this->numarUrmaritori = c.numarUrmaritori;
		this->numarPostari = c.numarPostari;
		this->numarLikes = new int[c.numarPostari];
		for (int i = 0; i < c.numarPostari; i++) {
			this->numarLikes[i] = c.numarLikes[i];
		}
		this->AppSocialMedia = c.AppSocialMedia;

	}

	ProfilCelebru operator=(const ProfilCelebru& c) //operator=
	{
		ProfilUtilizator::operator=(c);
		if (this != &c) {

			delete[]this->numarLikes;
			this->numarUrmaritori = c.numarUrmaritori;
			this->numarPostari = c.numarPostari;
			this->numarLikes = new int[c.numarPostari];
			for (int i = 0; i < c.numarPostari; i++) {
				this->numarLikes[i] = c.numarLikes[i];
			}
			this->AppSocialMedia = c.AppSocialMedia;
		}
		return *this;
	}



	//get
	float getNrUrmaritori() 
	{
		return this->numarUrmaritori;
	}
	int getNumarPostari() {

		return this->numarPostari;
	}

	int* getNrLikes() {
		return this->numarLikes;
	}

	string getApp() {
		return this->AppSocialMedia;
	}


	//set

	void setNrUrmaritori(float numarUrmaritori) {
		if (numarUrmaritori > 0) {
			this->numarUrmaritori=numarUrmaritori;
		}
		else {
			this->numarUrmaritori = 0;
		}
	}

	void setNrPostari(int numarPostari) {
		this->numarPostari = numarPostari;
	}

	void setNrLikes(int numarPostari, int* numarLikes)
	{

		if (this->numarLikes != NULL) {
			delete[]this->numarLikes;
		}
		this->numarPostari = numarPostari;

		this->numarLikes = new int[numarPostari];
		for (int i = 0; i < numarPostari; i++)
		{
			this->numarLikes[i] = numarLikes[i];
		}

	}

	void setApp(string AppSocialMedia)
	{
		this->AppSocialMedia = AppSocialMedia;
	}



	friend ostream& operator<< (ostream& out, const ProfilCelebru& c) //op <<
	{
		out << (ProfilUtilizator&)c << endl;
		out << "nr urm: " << c.numarUrmaritori << endl;
		out << "nr post: " << c.numarPostari << endl;
		for (int i = 0; i < c.numarPostari; i++)
		{
			out << "aprecieri: " << c.numarLikes << endl;
		}
		out << "app: " << c.AppSocialMedia << endl;
		return out;
	}


	friend istream& operator>> (istream& in, ProfilCelebru& c) //op >>
	{
		cout << "nr urm: ";
		in >> c.numarUrmaritori;

		cout << "app: ";
		in >> c.AppSocialMedia;

		cout << "numar postari ";
		in >> c.numarPostari;

		delete[]c.numarLikes;
		c.numarLikes = new int[c.numarPostari];
		for (int i = 0; i < c.numarPostari; i++) {
			cout << "likes sunt: " << i + 1;
			in >> c.numarLikes[i];
		}


		return in;

	}


	~ProfilCelebru() { //destructor
		if (this->numarLikes != NULL)
			delete[]this->numarLikes;
	}



};




int main() {

	ProfilUtilizator u1; //apel constr fara param
	ProfilUtilizator u2("dadlles","12345","Diana","stefan.dianna@gmail.com", 20, 5, new string [5] { "iulia","ana","ema","mihaela","cristiana"}); //apel constr cu toti param
	ProfilUtilizator u3(u2); //apel constructor de copiere
	ProfilUtilizator u4;
	u4 = u2;//apel op =
	cout << u3.getVarsta();//apel getter
	u2.setVarsta(18);//apel setter
	cout << u2;//apel <<
	cin >> u3;//apel >>
	++u2;//apel ++ pre
	u4++; //apel post ++
	ProfilUtilizator u5;
	u5 += 30; //apel +=
	--u3;//apel -- pre
	u5--;//apel -- post




	ProfilCelebru p1;//apel constr fara param
	ProfilCelebru p2("aaa", "asd", "sad", "asdf", 22, 1, new string[1]{ "asd" }, 10, 1, new int[1] {200}, "insta");//apel constr cu toti param
	ProfilCelebru p3(p2);
	ProfilCelebru p4;
	p4 = p1;
	cout << p3.getApp();
	p3.setApp("fb");
	cout << p2;
	cin >> p3;
	



	return 0;
}
