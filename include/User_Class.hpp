#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <map>

#include"Tweet_Class.hpp"
#include"Display_Class.hpp"


class tweet;
class twitterak;

//================================================================================ User_Class ================================================================================ 

class user
{
//=================== Friends ===================

friend void tweet::set_user_age(user);                            // friend with Tweet_Class to set user age
friend void tweet::rq_tweet(twitterak&, std::string);              // friend with Tweet_Class to push_back tweets on vector
friend void display::show_tweet(twitterak);                       // friend with Twitterak_Class to show tweets
friend void display::show_tweet(twitterak, std::string, int);     // friend with Twitterak_Class to show tweets
friend void display::show_tweet(twitterak, std::string);          // friend with Twitterak_Class to show tweets
friend void tweet::delete_tweet(twitterak, int);                  // friend with Twitterak_Class to delete a tweet
friend void tweet::edit_tweet(twitterak, int);                    // friend with Twitterak_Class to edit a tweet
// friend void twitterak::run();


    public:
//===================== Gets ======================
        std::string get_name()const;                              // returns the name of the user
        std::string get_username()const;                          // returns the username of the user
        std::string get_biography()const;                         // returns the biography of the user
        std::string get_link()const;                              // returns the link of the user
        std::string get_birthday()const;                          // returns the date of birth of the user
        std::string get_phone()const;                             // returns the phone number of the user
        std::string get_password()const;                          // returns the password of the user's account
        std::string get_header()const;                            // returns the color of the header that user had chosen 
        std::string get_country()const;                           // returns the country of the user
        int get_last_number();                                    // returns the last tweet's number

//====================== sets =====================

        void set_name(std::string);                               // sets the name of a user
        void set_username(std::string);                           // sets the username of a user with a validation
        void set_biography(std::string);                          // sets the biography of a user
        void set_link(std::string);                               // sets the link of a user
        void set_birthday(std::string);                           // sets the date of birth of a user
        void set_phone(std::string);                              // sets the phone number of a user
        void set_password(std::string);                           // sets the password of the user's account
        void set_header(std::string);                             // sets the color of the header that user had chosen
        void set_country(std::string);                            // sets the country of the user

//=============== General functions =================

        void Delete_Account(twitterak &);                          // delets the account of the user
        void Show_Profile(twitterak &);                            // shows the information of a user itself
        void Edit(twitterak &, std::string, std::string);          // edits the user's information                                                                    
        void Tweet(std::string );                                  // make a normal tweet
        void Logout(twitterak &);                                  // logs out of the user's account
        void Push_Tweet(tweet);                                    // push a tweet into a vector
        void last_number();                                        // plus plus last_num variable
        void print_likers(int);
        void like(std::string ,int);
        void dislike(std::string, int);
        int Validating_Username(std::string);                      // the validation of a user's username
        std::string to_lower(std::string);                         // makes a string a lowercase
        std::string remove_atsing(std::string);                    // removes @ from the first of the user name
        bool validate_phone_number(std::string);                   // validate user's phone_number
        std::map <int, tweet> get_tweets();
        
             

    private:
        std::string Full_Name;
        std::string Username;
        std::string Biography;
        std::string Link;
        std::string Birthday;
        std::string Phone_Number;
        std::string Password;
        std::string Header;
        std::string Country;

        int last_num = 0;

        std::map <int, tweet> tweets;
};


#endif