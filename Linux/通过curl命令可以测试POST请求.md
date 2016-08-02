##命令

        curl "https://www.codewars.com/api/v1/code-challenges/anything-to-integer/javascript/train" \
         -X POST \
         -H "Authorization: some-api-key"

##结果

        {
           "success":true,
           "name":"Anything to integer",
           "slug":"anything-to-integer",
           "description":"Your task is to program a function which converts any input to an integer.\n\nDo not perform rounding, the fractional part should simply be discarded.\n\nIf converting the input to an integer does not make sense (with an object, for instance), the function should return 0 (zero).\n\nAlso, Math.floor(), parseInt() and parseFloat() are disabled for your unconvenience.\n\nOnegaishimasu!",
           "author":"Jake Hoffner",
           "rank":-6,
           "averageCompletion":125.4,
           "tags":[
              "Fundamentals",
              "Integers",
              "Data Types",
              "Numbers"
           ],
           "session":{
               "projectId":"523f66fba0de5d94410001cb",
               "solutionId":"53bc968d35fd2feefd000013",
               "setup":"function toInteger(n) {\n  \n}",
               "exampleFixture":"Test.expect(toInteger(\"4.55\") === 4)",
               "code":null
           }
        }