#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/filewritestream.h"

#include <iostream>

using namespace rapidjson;
using namespace std;

// #define ACCESS_TOKEN "1416523158"

class FakeRapidJsonInterface{
    public:
        string BuildCreateJson();
        string BuildRecognizeJson();
        string BuildStopRecognizeJson();
        string BuildCancelJson();
};
