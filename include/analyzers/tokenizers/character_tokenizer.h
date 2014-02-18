/**
 * @file character_tokenizer.h
 * @author Chase Geigle
 */

#ifndef _META_CHARACTER_TOKENIZER_H_
#define _META_CHARACTER_TOKENIZER_H_

#include "analyzers/token_stream.h"

namespace meta
{
namespace corpus
{
class document;
}
}

namespace meta
{
namespace analyzers
{

/**
 * Converts documents into streams of characters. This is the simplest
 * tokenizer.
 */
class character_tokenizer : public token_stream
{
  public:
      /**
       * Creates a character_tokenizer operating on the given document.
       */
      character_tokenizer(corpus::document& doc);

      /**
       * Obtains the next token in the document. This token will contain a
       * single character.
       */
      std::string next() override;

      /**
       * Determines if there are more tokens in the document.
       */
      operator bool() const override;

  private:
      std::string content_;
      uint64_t idx_;
};
}
}

#endif
