//
// Created by Patryk on 04.05.2017.
//

#include "MovieSubtitles.h"


void moviesubs::MicroDvdSubtitles::ShiftAllSubtitlesBy(int msec, int fps, stringstream *in, stringstream *out) {
    std::string in_content = in->str();
    std::string in_content_part;
    vector<int> fpses;
    vector<std::string> lines;
    int diff = (msec * fps) / 1000;
    std::smatch matches;
    std::regex pattern{R"((\{)([0-9]+)(\})(\{)([0-9]+)(\}))"};
    if (msec < 0) {
        throw NegativeFrameAfterShift(*this);
    } else if (fps < 0) {
        throw std::invalid_argument ("Fail");
    } else {
        for (int i = 0; i < in_content.length(); i++) {
            in_content_part += in_content[i];
            if (in_content[i] == '\n') {
                in_content_part.erase(in_content_part.size() - 1, 1);
                lines.push_back(in_content_part);
                if (std::regex_search(in_content_part, matches, pattern)) {
                    int parametr_1 = std::stoi(matches[2]) + diff;
                    int paramets_2 = std::stoi(matches[5]) + diff;
                    fpses.push_back(std::stoi(matches[5]));
                    stringstream ss;
                    ss << '{' << parametr_1 << '}' << '{' << paramets_2 << '}';
                    (*out) << std::regex_replace(in_content_part, pattern, ss.str());
                    (*out) << '\n';
                    in_content_part.clear();
                } else if (!std::regex_search(in_content_part, matches, pattern))
                    throw InvalidSubtitleLineFormat(*this);
            } else if (in_content[i + 1] == '\0') {
                lines.push_back(in_content_part);
                if (std::regex_search(in_content_part, matches, pattern)) {
                    int parametr_1 = std::stoi(matches[2]) + diff;
                    int paramets_2 = std::stoi(matches[5]) + diff;
                    stringstream ss;
                    ss << '{' << parametr_1 << '}' << '{' << paramets_2 << '}';
                    (*out) << std::regex_replace(in_content_part, pattern, ss.str());
                    (*out) << '\n';
                    in_content_part.clear();
                } else if (!std::regex_search(in_content_part, matches, pattern))
                    throw InvalidSubtitleLineFormat(*this);
            }

        }
        for(int k=fpses.size()-1;k>=0;k--){
            if(fpses[k]<fpses[k-1]) {
                throw SubtitleEndBeforeStart(*this, k, lines);
                break;
            }

        }

    }
}


int moviesubs::SubtitleEndBeforeStart::LineAt() const{
    return index+1;
}


std::string moviesubs::SubtitleEndBeforeStart::what() const{
    std::string out;
    out+="At line ";
    out+=std::to_string(index+1);
    out+=": ";
    out+=this->v[index];
    return out;
}

void moviesubs::SubRipSubtitles::ShiftAllSubtitlesBy(int msec, int fps, stringstream *in, stringstream *out){
    std::regex pattern{R"()"};
}

