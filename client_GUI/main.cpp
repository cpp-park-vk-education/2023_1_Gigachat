#include <Wt/WApplication.h>
#include <Wt/WBreak.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>
#include <Wt/WComboBox.h>


class IAuth : public Wt::WContainerWidget {
public:
    IAuth() { };

    void drawWidget(Wt::WContainerWidget *root);
    void linkWidgets(std::unique_ptr<Wt::WContainerWidget> test);

private:
    Wt::WComboBox* languageBox_;
    Wt::WLineEdit* loginEdit_;
    Wt::WLineEdit* passwordEdit_;
    Wt::WLineEdit* nicknameEdit_;

    void drawTest(Wt::WContainerWidget *root);

};

class ITest : public Wt::WContainerWidget {
public:
    ITest() { };

    void drawWidget(Wt::WContainerWidget *root);

private:
    void drawAuth(Wt::WContainerWidget *root);

};

void ITest::drawWidget(Wt::WContainerWidget *root) {
    //
}

void ITest::drawAuth(Wt::WContainerWidget *root) {
    //
}

void IAuth::drawWidget(Wt::WContainerWidget *root) {
    root->addWidget(std::make_unique<Wt::WText>("Auth"));
    root->addWidget(std::make_unique<Wt::WBreak>());
    root->addWidget(std::make_unique<Wt::WBreak>());
    root->addWidget(std::make_unique<Wt::WText>("Login:"));
    root->addWidget(std::make_unique<Wt::WBreak>());
    loginEdit_ = root->addWidget(std::make_unique<Wt::WLineEdit>());
    root->addWidget(std::make_unique<Wt::WBreak>());
    root->addWidget(std::make_unique<Wt::WText>("Password:"));
    root->addWidget(std::make_unique<Wt::WBreak>());
    passwordEdit_ = root->addWidget(std::make_unique<Wt::WLineEdit>());
    root->addWidget(std::make_unique<Wt::WBreak>());
    root->addWidget(std::make_unique<Wt::WText>("Nickname:"));
    root->addWidget(std::make_unique<Wt::WBreak>());
    nicknameEdit_ = root->addWidget(std::make_unique<Wt::WLineEdit>());
    root->addWidget(std::make_unique<Wt::WBreak>());
    root->addWidget(std::make_unique<Wt::WText>("Language:"));
    root->addWidget(std::make_unique<Wt::WBreak>());

    languageBox_ = root->addWidget(std::make_unique<Wt::WComboBox>());
    languageBox_->addItem("Choose language");
    languageBox_->addItem("English");
    languageBox_->addItem("Russian");
    languageBox_->addItem("Elvish");

    root->addWidget(std::make_unique<Wt::WBreak>());    // line break
    auto loginButton = root->addWidget(std::make_unique<Wt::WPushButton>("Log in"));
    loginButton->setMargin(20, Wt::Side::Top);
    auto registerButton = root->addWidget(std::make_unique<Wt::WPushButton>("Register"));
    registerButton->setMargin(50, Wt::Side::Left);

    root->addWidget(std::make_unique<Wt::WBreak>());
}

void IAuth::drawTest(Wt::WContainerWidget *root) {
    //
}

void IAuth::linkWidgets(std::unique_ptr<Wt::WContainerWidget> test) {
    //
}

class MainApplication : public Wt::WApplication
{
public:
    MainApplication(const Wt::WEnvironment& env);

private:
    std::unique_ptr<IAuth> auth_;
    std::unique_ptr<ITest> test_;

    void greet() {std::cout<<123;}
};

MainApplication::MainApplication(const Wt::WEnvironment& env)
        : WApplication(env)
{
    setTitle("GigaChat");  // application title
    auto test = root();  // KFC

    auth_ = std::make_unique<IAuth>();
    test_ = std::make_unique<ITest>();

    auth_->drawWidget(root());


    /*
     * Connect signals with slots
     *
     * - simple Wt-way: specify object and method
     */
    // loginButton->clicked().connect(this, &MainApplication::greet);

    /*
     * - using an arbitrary function object, e.g. useful to bind
     *   values with std::bind() to the resulting method call
     */
    // nicknameEdit_->enterPressed().connect(std::bind(&MainApplication::greet, this));

    /*
     * - using a lambda:
     */
    /*loginButton->clicked().connect([=]() {
        std::cerr << "Hello there, " << nicknameEdit_->text() << std::endl;
    });*/
}

/*void MainApplication::greet()
{
    *//*
     * Update the text, using text input into the nameEdit_ field.
     *//*
    greeting_->setText("Hello there, " + nicknameEdit_->text());
}*/

int main(int argc, char **argv)
{
    /*
     * Your main method may set up some shared resources, but should then
     * start the server application (FastCGI or httpd) that starts listening
     * for requests, and handles all of the application life cycles.
     *
     * The last argument to WRun specifies the function that will instantiate
     * new application objects. That function is executed when a new user surfs
     * to the Wt application, and after the library has negotiated browser
     * support. The function should return a newly instantiated application
     * object.
     */
    return Wt::WRun(argc, argv, [](const Wt::WEnvironment &env) {
        return std::make_unique<MainApplication>(env);
    });
}
