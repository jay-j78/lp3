#include<iostream>
#include<string>
#include<algorithm> // Used for string transformation
using namespace std;

int main(){
    string user; // Variable to store user's message
    string name; // Variable to store user's name
    
    cout<<"----------------------------------------"<<endl;
    cout<<"          SMART CUSTOMER CHATBOT            ";
    cout<<"----------------------------------------"<<endl;

    cout<<"Bot: Hello welcome to our store!"<<endl;
    cout<<"Bot: May I know yur name?"<<endl;

    cout<<"You: ";
    // Use getline to allow spaces in the name
    getline(cin,name);

    cout<<"Bot: hi "<<name<<"! how can i help you?"<<endl;
    cout<<"        -product\n";
    cout<<"        -price\n";
    cout<<"        -offers\n";
    cout<<"        -delivery\n";
    cout<<"        -contact\n";
    cout<<"type bye to exit"<<endl;
    
    // Infinite loop to keep chatting until user types "bye"
    while(true){
        cout<<"user: ";
        getline(cin,user); // Get input from user

        // Convert the user's input entirely to lowercase so it's easier to match
        transform(user.begin(),user.end(),user.begin(),::tolower);

        // Check keywords using an if-else ladder
        if(user=="hi"||user=="hello"){
            cout<<"Bot: hello "<<name<<"! how can i help you?"<<endl;
        }
        else if(user=="product"|| user=="products"){
            cout<<"Bot: available products are: \n1. laptop\n2. mobile\n3. headphones\n4. smart watch"<<endl;
        }
        else if(user=="laptop"){
            cout<<"Bot: we have dell, hp, lenovo, apple laptops available"<<endl;
        }
        else if(user=="mobile"){
            cout<<"Bot: we have samsung, apple, oneplus, xiaomi mobiles available"<<endl;
        }
        else if(user=="headphones"){
            cout<<"Bot: we have bose, sony, jbl headphones available"<<endl;
        }
        else if(user=="smart watch"){
            cout<<"Bot: we have apple watch, samsung watch, fitbit smart watch available"<<endl;
        }
        else if(user=="price"){
            cout<<"Bot: the price range for our products is as follows:\n1. laptop: $500-$2000\n2. mobile: $200-$1500\n3. headphones: $50-$500\n4. smart watch: $100-$1000"<<endl;
        }
        else if(user=="offers"){
            cout<<"Bot: we currently have a 10% discount on all laptops and a 20% discount on select mobile phones!"<<endl;
        }
        else if(user=="delivery"){
            cout<<"Bot: we offer free delivery for orders above $50. Delivery time is typically 3-5 business days."<<endl;
        }
        else if(user=="contact"){
            cout<<"Bot: you can contact us at sai@gmail.com\n 9876543210"<<endl;
        }
        else if(user=="payment"){
            cout<<"Bot: we accept\n";
            cout<<"1. credit/debit cards\n2. net banking\n3. mobile wallets\n4. cash on delivery"<<endl;
        }
        else if(user=="bye"){
            cout<<"Bot: thank you for visiting our store! have a great day!"<<endl;
            break; // Exit the while loop to end program
        }
        else{
            // Fallback if the bot doesn't understand the word
            cout<<"Bot: sorry i didnt understand that. can you please rephrase?"<<endl;
            cout<<"        -product\n";
            cout<<"        -price\n";   
            cout<<"        -offers\n";
            cout<<"        -delivery\n";
            cout<<"        -contact\n";
            cout<<"        -payment\n";
            cout<<"use this phrases to get the information you need!"<<endl;
        }
    }
    return 0;
}