#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Unique ID generator (simple static counter)
class IDGenerator {
public:
    static int postID;
    static int commentID;
    static int replyID;

    static int getNewPostID() {
        return ++postID;
    }

    static int getNewCommentID() {
        return ++commentID;
    }

    static int getNewReplyID() {
        return ++replyID;
    }
};

// Initializing static members
int IDGenerator::postID = 0;
int IDGenerator::commentID = 0;
int IDGenerator::replyID = 0;

// Reply class
class Reply {
public:
    int replyID;
    string content;

    Reply(string content) {
        this->replyID = IDGenerator::getNewReplyID();
        this->content = content;
    }

    void display() const {  // Mark display as const
        cout << "\t\tReply ID: " << replyID << ": " << content << endl;
    }
};

// Comment class
class Comment {
public:
    int commentID;
    string content;
    vector<Reply> replies;

    Comment(string content) {
        this->commentID = IDGenerator::getNewCommentID();
        this->content = content;
    }

    void addReply(Reply reply) {
        replies.push_back(reply);
    }

    void display() const {  // Mark display as const
        cout << "\tComment ID: " << commentID << ": " << content << endl;
        for (const Reply& reply : replies) {
            reply.display();
        }
    }
};

// Post class
class Post {
public:
    int postID;
    string content;
    vector<Comment> comments;

    Post(string content) {
        this->postID = IDGenerator::getNewPostID();
        this->content = content;
    }

    void addComment(Comment comment) {
        comments.push_back(comment);
    }

    void display() const {  // Mark display as const
        cout << "Post ID: " << postID << ": " << content << endl;
        for (const Comment& comment : comments) {
            comment.display();
        }
    }
};

// Function to display all posts
void displayAllPosts(const vector<Post>& posts) {
    if (posts.empty()) {
        cout << "No posts available.\n";
    } else {
        for (const Post& post : posts) {
            post.display();
            cout << "--------------------\n";
        }
    }
}

// Function to display a single post by its ID
void displayPostByID(const vector<Post>& posts, int postID) {
    bool found = false;
    for (const Post& post : posts) {
        if (post.postID == postID) {
            post.display();
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Post ID not found.\n";
    }
}

// Main application logic
int main() {
    vector<Post> posts;
    int choice;

    while (true) {
        cout << "\n1. Create Post\n2. Comment on Post\n3. Reply to Comment\n4. View Post\n5. View All Posts\n6. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore();  // To clear the newline character from the input buffer

        if (choice == 1) {
            // Create a new post
            string content;
            cout << "Enter your post content: ";
            getline(cin, content);

            Post newPost(content);
            posts.push_back(newPost);
            cout << "Post created successfully!\n";

        } else if (choice == 2) {
            // Comment on a specific post
            if (posts.empty()) {
                cout << "No posts available to comment on.\n";
                continue;
            }

            int postID;
            cout << "Enter the Post ID you want to comment on: ";
            cin >> postID;
            cin.ignore();  // To clear the newline character from the input buffer

            bool found = false;
            for (Post& post : posts) {
                if (post.postID == postID) {
                    string content;
                    cout << "Enter your comment: ";
                    getline(cin, content);

                    Comment newComment(content);
                    post.addComment(newComment);
                    cout << "Comment added successfully!\n";
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Post ID not found.\n";
            }

        } else if (choice == 3) {
            // Reply to a specific comment
            if (posts.empty()) {
                cout << "No posts available to reply to.\n";
                continue;
            }

            int postID, commentID;
            cout << "Enter the Post ID containing the comment you want to reply to: ";
            cin >> postID;
            cin.ignore();

            bool postFound = false, commentFound = false;
            for (Post& post : posts) {
                if (post.postID == postID) {
                    postFound = true;
                    if (post.comments.empty()) {
                        cout << "No comments available on this post.\n";
                        break;
                    }

                    cout << "Enter the Comment ID you want to reply to: ";
                    cin >> commentID;
                    cin.ignore();

                    for (Comment& comment : post.comments) {
                        if (comment.commentID == commentID) {
                            string content;
                            cout << "Enter your reply: ";
                            getline(cin, content);

                            Reply newReply(content);
                            comment.addReply(newReply);
                            cout << "Reply added successfully!\n";
                            commentFound = true;
                            break;
                        }
                    }

                    if (!commentFound) {
                        cout << "Comment ID not found.\n";
                    }
                    break;
                }
            }

            if (!postFound) {
                cout << "Post ID not found.\n";
            }

        } else if (choice == 4) {
            // View a specific post by ID
            if (posts.empty()) {
                cout << "No posts available to view.\n";
                continue;
            }

            int postID;
            cout << "Enter the Post ID you want to view: ";
            cin >> postID;
            cin.ignore();
            displayPostByID(posts, postID);

        } else if (choice == 5) {
            // View all posts
            displayAllPosts(posts);

        } else if (choice == 6) {
            // Exit the program
            cout << "Exiting...\n";
            break;

        } else {
            cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}