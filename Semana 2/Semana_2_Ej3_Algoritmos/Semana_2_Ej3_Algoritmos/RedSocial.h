#pragma once
#include <string>
using namespace std;
class RedSocial {
	private:
		string facebook;
		string googleplus;
		string twitter;
		string whatsapp;

	public:
		RedSocial() {}
		~RedSocial() {}
		RedSocial(string fb, string gplus, string tw, string wsp) {
			facebook = fb;
			googleplus = gplus;
			twitter = tw;
			whatsapp = wsp;
		}

		string getFacebook() { return facebook; }
		string getGooglePlus() { return googleplus; }
		string getTwitter() { return twitter; }
		string getWhatsapp() { return whatsapp; }

		void setFacebook(string fb) { ((fb != "x") ? facebook = fb : facebook = ""); }
		void setGooglePlus(string gplus) { ((gplus != "x") ? googleplus = gplus : googleplus = ""); }
		void setTwitter(string tw) { ((tw != "x") ? twitter = tw : twitter = ""); }
		void setWhatsapp(string wsp) { ((wsp != "x") ? whatsapp = wsp : whatsapp = ""); }
		void toString() {
			cout << "Facebook: " << ((facebook != "") ? facebook : "No existe.") << "\t";
			cout << "Google+: " << ((googleplus != "") ? googleplus : "No existe.") << "\t";
			cout << "Twitter: " << ((twitter != "") ? twitter : "No existe.") << "\t";
			cout << "Whatsapp: " << ((whatsapp != "") ? whatsapp : "No existe.");
		}
};