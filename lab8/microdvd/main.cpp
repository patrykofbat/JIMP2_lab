//
// Created by Patryk on 04.05.2017.
//

#include "MovieSubtitles.h"

using moviesubs::MicroDvdSubtitles;
using moviesubs::NegativeFrameAfterShift;
using moviesubs::SubtitleEndBeforeStart;
using moviesubs::InvalidSubtitleLineFormat;

int main(){
        stringstream in {"{0}{250}TEXT\n{260}{300}NEWLINE\n{280}{350} Longer text of subtitles"};
        stringstream out;
        stringstream ex;
        std::string nazwa = "patryk\n";
        auto sub = std::make_unique<MicroDvdSubtitles>();
        sub->ShiftAllSubtitlesBy(300, 25, &in, &out);
        std::cout<<nazwa.size();


    return 0;

}

