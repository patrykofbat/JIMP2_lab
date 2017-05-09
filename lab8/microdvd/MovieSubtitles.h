//
// Created by Patryk on 04.05.2017.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H
#include<sstream>
#include<regex>
#include<string>
#include <iostream>
#include <exception>
#include <stdexcept>
#include <vector>

using ::std::stringstream;
using ::std::vector;
namespace moviesubs {
    class Shifting {
    public:
        virtual void ShiftAllSubtitlesBy(int msec, int fps, stringstream *in, stringstream *out)=0;
    };

    class MovieSubtitles:public Shifting {
    public:
        MovieSubtitles() {};

        ~MovieSubtitles() {};

        virtual void ShiftAllSubtitlesBy(int msec, int fps, stringstream *in, stringstream *out) {};
    };

    class MicroDvdSubtitles : public MovieSubtitles {
    public:
        MicroDvdSubtitles() {};

        ~MicroDvdSubtitles() {};

        virtual void ShiftAllSubtitlesBy(int msec, int fps, stringstream *in, stringstream *out);

    };

    class InvalidSubtitleLineFormat {
    public:
        InvalidSubtitleLineFormat(MicroDvdSubtitles &m) {};

        ~InvalidSubtitleLineFormat() {};
    };

    class NegativeFrameAfterShift {
    public:
        NegativeFrameAfterShift(MicroDvdSubtitles &m) {};

        ~NegativeFrameAfterShift() {};
    };

    class SubtitleEndBeforeStart {
    private:
        int index;
        vector<std::string> v;
    public:
        SubtitleEndBeforeStart(MicroDvdSubtitles &m, int k, vector<std::string> lines) {
            this->index = k;
            v = lines;
        };

        ~SubtitleEndBeforeStart() {};

        int LineAt() const;

        std::string what() const;
    };
    class SubRipSubtitles:public MovieSubtitles{
    public:
        SubRipSubtitles(){};
        ~SubRipSubtitles(){};
        virtual void ShiftAllSubtitlesBy(int msec, int fps, stringstream *in, stringstream *out);

    };

}

#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
