#include "fakerapidjsoninterface.h"
#include <iostream>
#include <fstream>
#include <stdio.h>

static void printIt(const Value &doc) {
    char writeBuffer[65536];
    FileWriteStream os(stdout, writeBuffer, sizeof(writeBuffer));
    PrettyWriter<FileWriteStream> writer(os);
    doc.Accept(writer);
    cout << endl;
}

string FakeRapidJsonInterface::BuildCreateJson() {

    StringBuffer s;
    Writer<StringBuffer> writer(s);

    
    
    writer.StartObject();
    writer.Key("action");
    writer.String("create");
    
    writer.Key("asr_app_type");
    // writer.String("AICLOUD_ALADDIN");
    writer.String("SKTVOCD");
    
    writer.Key("audio_format");
    writer.String("FMT8K_LINEAR_PCM16");

    // writer.Key("token");
    // writer.Bool(false);

    writer.Key("server_type");
    writer.String("BUILD_STG");
    
    writer.Key("poc_id");
    writer.String("test.b2b.wooribank");

    writer.Key("partial_results");
    writer.Bool(true);

    writer.Key("continual_mode");
    writer.Bool(false);
    
    writer.Key("word_alignment");
    writer.Bool(false);
    
    writer.Key("punctuation");
    writer.Bool(false);
   
    writer.Key("server_epd");
    writer.Bool(false);

    writer.Key("asr_context");
    writer.StartObject();

    // writer.Key("task");
    // writer.String("eng_yn");
    // writer.Key("scen_id");
    // writer.String("INPUT_USE_ID");
    // writer.Key("scen_task");

    writer.EndObject();

    writer.EndObject();

    return s.GetString();
}

string FakeRapidJsonInterface::BuildRecognizeJson() {
    StringBuffer s;
    Writer<StringBuffer> writer(s);

    
    writer.StartObject();
    writer.Key("action");
    writer.String("recognize");

    writer.Key("final");
    writer.Bool(true);

    // writer.Key("resultIndex");
    // writer.Int(0);

    // writer.Key("asr_context");
    // writer.StartObject();
    //  writer.Key("scen_id");
    // writer.String("4digit");

    // // writer.Key("scen_task");

    // // writer.String("eng_yn");
   
    // // writer.Key("scene_text");
    
    // // writer.StartArray();
    
    // // writer.String(p_file);
    // // writer.String("아리야");
    // // writer.String("날씨");

    // // writer.EndArray();
    // writer.EndObject();
    writer.EndObject();

    return s.GetString();
}

string FakeRapidJsonInterface::BuildStopRecognizeJson() {
    StringBuffer s;
    Writer<StringBuffer> writer(s);
    
    writer.StartObject();
    writer.Key("action");
    writer.String("stop");
    
    writer.EndObject();

    return s.GetString();
}

string FakeRapidJsonInterface::BuildCancelJson() {
    StringBuffer s;
    Writer<StringBuffer> writer(s);
    
    writer.StartObject();
    writer.Key("action");
    writer.String("cancel");
    
    writer.EndObject();

    return s.GetString();
}