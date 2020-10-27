#ifndef WORDS_COUNTER_H
#define WORDS_COUNTER_H

#include <sstream>
#include <string>
#include <unordered_set>
#include <string_view>

#include "ireader_delegate.h"

class WordsCounter : public IReaderDelegate {
   public:
    // IReaderDelegate interface
    void addBuffer(std::string_view buffer) override;
    void readingFinished() override;

    size_t uniqueWordsCount() const;

   private:
    std::unordered_set<std::string> dictionary_;
    std::stringstream input_stream_;
};

#endif  // WORDS_COUNTER_H