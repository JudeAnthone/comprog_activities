#include <iostream>
#include <string>

using namespace std;

// A simple struct to represent a post
struct Post {
    string content;
    string comments[10]; // Max 10 comments
    int comment_count;

    struct Reply {
        int comment_id;
        string reply;
    } replies[10]; // Max 10 replies per comment

    int reply_count; // Total replies

    // Constructor to initialize the post
    Post() : comment_count(0), reply_count(0) {}
};

// Array to store posts (10 posts max)
Post social_media_platform[10];

// Function to create a new post
int create_post(const string& content) {
    static int post_id = 0; // Unique ID for each post
    if (post_id >= 10) { // Limit to 10 posts for simplicity
        cout << "Max posts reached." << endl;
        return -1;
    }
    social_media_platform[post_id].content = content;
    return post_id++;
}

// Function to comment on a post
void comment_on_post(int post_id, const string& content) {
    if (post_id < 0 || post_id >= 10) {
        cout << "Invalid post ID." << endl;
        return;
    }
    if (social_media_platform[post_id].comment_count >= 10) {
        cout << "Max comments reached." << endl;
        return;
    }
    social_media_platform[post_id].comments[social_media_platform[post_id].comment_count++] = content;
}

// Function to reply to a comment
void reply_to_comment(int post_id, int comment_id, const string& content) {
    if (post_id < 0 || post_id >= 10 || comment_id < 0 || comment_id >= 10) {
        cout << "Invalid ID." << endl;
        return;
    }
    if (social_media_platform[post_id].reply_count >= 10) {
        cout << "Max replies reached." << endl;
        return;
    }
    social_media_platform[post_id].replies[social_media_platform[post_id].reply_count].comment_id = comment_id;
    social_media_platform[post_id].replies[social_media_platform[post_id].reply_count++].reply = content;
}

// Function to view a post
void view_post(int post_id) {
    if (post_id < 0 || post_id >= 10) {
        cout << "Invalid post ID." << endl;
        return;
    }
    cout << "Post " << post_id << ": " << social_media_platform[post_id].content << endl;
    cout << "Comments: ";
    for (int i = 0; i < social_media_platform[post_id].comment_count; i++) {
        cout << "[" << i << "] " << social_media_platform[post_id].comments[i] << " ";
    }
    cout << endl;

    cout << "Replies: ";
    for (int i = 0; i < social_media_platform[post_id].reply_count; i++) {
        cout << "Reply to comment [" << social_media_platform[post_id].replies[i].comment_id << "]: " 
             << social_media_platform[post_id].replies[i].reply << " ";
    }
    cout << endl;
}

// Function to view all posts
void view_all_posts() {
    cout << "All posts:" << endl;
    for (int i = 0; i < 10; i++) {
        if (!social_media_platform[i].content.empty()) {
            cout << "Post [" << i << "]: " << social_media_platform[i].content << endl;
        }
    }
}

// Main function
int main() {
    // Example usage
    int post_id = create_post("Hey everyone! Just got back from class!");
    cout << "Created post with ID " << post_id << endl;

    comment_on_post(post_id, "Sounds awesome!");
    comment_on_post(post_id, "What class was it?");

    reply_to_comment(post_id, 0, "It was pretty cool!");
    reply_to_comment(post_id, 1, "I loved it too!");

    view_post(post_id); // Show the post, comments, and replies
    view_all_posts();   // Show all posts

    cout << "Goodbye!" << endl;

    return 0;
}