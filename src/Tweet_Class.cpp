#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <unordered_set>

#include "Tweet_Class.hpp"
#include "Twitterak_Class.hpp"

//==================================================================  Get_Functions =================================================================

std::string tweet::get_tweetType() const                                                              // returns the type of tweet(quote/retweet)
{
    return tweet_type;
}

//------------------------------------------------------------------------

std::string tweet::get_sefTweet() const                                                                // returns the user's tweet
{
    return self_tweet;
}

//------------------------------------------------------------------------

std::string tweet::get_ownerName() const                                                                // returns the name of the owner of another user
{
    return owner_name;
}

//------------------------------------------------------------------------

std::string tweet::get_ownerUser_name() const                                                            // returns the username of the owner of another user
{
    return owner_username;
}

//------------------------------------------------------------------------

std::string tweet::get_ownerTweet() const                                                                 // returns the tweet of the owner of another user
{
    return owner_tweet;
}

//------------------------------------------------------------------------

std::string tweet::get_name() const                                                                        // returns the name of the user
{
    return name;
}

//------------------------------------------------------------------------

std::string tweet::get_user_name() const                                                                    // returns the username of the user
{
    return user_name;
}

//------------------------------------------------------------------------

int tweet::get_number() const                                                                                // returns the tweet's number
{
    return number;
}

//------------------------------------------------------------------------

int tweet::get_user_age() const                                                                               // returns the age of the user 
{
    return user_age;
}

//==================================================================  Set_Functions =================================================================

void tweet::set_tweetType(std::string type)                                                                    // sets the type of a tweet(quote/retweet)
{
    tweet_type = type;
}

//------------------------------------------------------------------------

void tweet::set_selfTweet(std::string tweet)                                                                    // sets the user's tweet
{
    self_tweet = tweet;
}

//------------------------------------------------------------------------

void tweet::set_ownerName(std::string name)                                                                      // sets the name of the owner of another user
{
    owner_name = name;
}

//------------------------------------------------------------------------

void tweet::set_ownerUser_name(std::string user_name)                                                            // sets the username of the owner of another user
{ 
    owner_username = user_name;
}

//------------------------------------------------------------------------

void tweet::set_ownerTweet(std::string tweet)                                                                      // sets the tweet of the owner of another user
{
    owner_tweet = tweet;
}

//------------------------------------------------------------------------

void tweet::set_name(std:: string name)                                                                             // sets the name of the user
{
    this->name = name;
}

//------------------------------------------------------------------------

void tweet::set_user_name(std:: string user_name)                                                                    // sets the username of the user
{
    this->user_name = user_name;
}

//------------------------------------------------------------------------

void tweet::set_number(int number)                                                                                   // sets the tweet's number
{
    this->number = number;
}

//------------------------------------------------------------------------

void tweet::set_user_age(user usr)                                                                                    // sets the age of the user 
{
    int user_birth;
    user_birth = std::stoi(usr.get_birthday().substr(0,3));
    user_age = 2023 - user_birth;
}

//================================================================  General_Functions ===============================================================

void tweet::delete_tweet(twitterak app, int number)                                                  // deletes a tweet of a user 
{
    int size = app.users[app.logedin_user].tweets.size();

    for (int i = 0; i < size; i++)
    {
        if (app.users[app.logedin_user].tweets[i].get_number() == number)
            app.users[app.logedin_user].tweets.erase(app.users[app.logedin_user].tweets.begin()+i);

        else
            std::cout << "! There is no tweet with this number.\n";
    }
}

//------------------------------------------------------------------------

void tweet::edit_tweet()                                                                                              // edits a tweet of a user
{
   
}

//------------------------------------------------------------------------

void tweet::rq_tweet(twitterak app, std:: string type)                                                                // quote tweet or retweet
{
    tweet rq_tweet;
    rq_tweet.set_tweetType(type);
    rq_tweet.set_ownerTweet(this->self_tweet);
    rq_tweet.set_ownerUser_name(this->user_name);
    rq_tweet.set_ownerName(this->user_name);

    rq_tweet.set_name(app.users[app.logedin_user].get_name());
    rq_tweet.set_user_name(app.users[app.logedin_user].get_username());
    rq_tweet.set_number(app.users[app.logedin_user].get_last_number() + 1);

    if(type == "qoute")
    {
        std::string tweet;
        std::cout << "$ your tweet : ";
        std::getline(std::cin, tweet);
        std::cin.ignore();

        rq_tweet.set_selfTweet(tweet);
    }

    app.users[app.logedin_user].Push_Tweet(rq_tweet);
}

//------------------------------------------------------------------------

void tweet::fetch_hashtags(twitterak &app, std::string tweet)                                                    // finds and saves hashtags of user's tweet
{
    std::string hashtag;
    int tsize = hashtags.size();

    for(int i = 0; i < tsize; i++)
    {
        if(tweet[i] == '#')
        {
            for(int j = i+1; j < tsize; j++)
            {
                if(tweet[j] != ' ')
                {
                    hashtag += tweet[j];
                }
                else
                {
                    if(!hashtag.empty())
                    {
                        hashtags.push_back(hashtag);
                        app.Hashtags[hashtag] = *this;
                    }
                    hashtag = "";
                    i = j;
                    break;
                }
            }
        }
    }
    hashtags.push_back(hashtag);

}