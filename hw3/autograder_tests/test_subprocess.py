import unittest
from gradescope_utils.autograder_utils.decorators import weight
from gradescope_utils.autograder_utils.decorators import visibility
import subprocess
import inspect
import io


class TestDiff(unittest.TestCase):
    def setUp(self):
        pass

    def helperFunction(self, test_name=""):
        test_name = inspect.stack()[1][3]
        test = subprocess.run(["./"+test_name], stdout=subprocess.PIPE, stderr=subprocess.PIPE,timeout=2)
        output = test.stderr.decode('utf-8').strip()

        # Standard unit test case with an associated error message 
        self.assertTrue( output == "", msg=output)
        self.assertTrue( test.returncode==0, msg="Program crashed (probably segfault), Return code: " + str(test.returncode))


    @weight(3)
    def test_compile(self):
        #Title used by Gradescope
        """Clean Compile: Run student's makefile"""

        test = subprocess.Popen(["make"], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        output = test.stderr.read().strip().decode('utf-8')
        test.kill()

        # Standard unit test case with an associated error message
        self.assertTrue( output == "", msg=output)
        test.terminate()
    
    @weight(2)
    def test_post1(self):
        """ test Post 1: constructor. """
        self.helperFunction()

    @weight(1)
    def test_post2(self):
        """ test Post 2: getMessageId """
        self.helperFunction()

    @weight(1)
    def test_post3(self):
        """ test Post 3: getOwnerId """
        self.helperFunction()

    @weight(1)
    def test_post4(self):
        """ test Post 4: getMessage """
        self.helperFunction()

    @weight(1)
    def test_post5(self):
        """ test Post 5: getLikes """
        self.helperFunction()

    @weight(2)
    def test_post6(self):
        """ test Post 6: correct values for default constructor """
        self.helperFunction()

    @weight(2)
    def test_post7(self):
        """ test Post 7: getAuthor """
        self.helperFunction()

    @weight(2)
    def test_post8(self):
        """ test Post 8: getIsPublic """
        self.helperFunction()

    @weight(2)
    def test_post9(self):
        """ test Post 9: displayPost  """
        self.helperFunction()

    @weight(2)
    def test_ipost1(self):
        """ test IncomingPost 1: default constructor. """
        self.helperFunction()

    @weight(2)
    def test_ipost2(self):
        """ test IncomingPost 2: parameterized constructor """
        self.helperFunction()

    @weight(2)
    def test_ipost3(self):
        """ test IncomingPost 3: getAuthor """
        self.helperFunction()

    @weight(2)
    def test_ipost4(self):
        """ test IncomingPost 4: getIsPublic """
        self.helperFunction()

    @weight(2)
    def test_ipost5(self):
        """ test IncomingPost 5: toString 1 """
        self.helperFunction()

    @weight(2)
    def test_ipost6(self):
        """ test IncomingPost 6: toString 2 (isPublic) """
        self.helperFunction()

    @weight(2)
    def test_ipost7(self):
        """ test IncomingPost 7: toString 3 """
        self.helperFunction()


    @weight(5)
    def test_virtual1(self):
        """ test virtual 1: getAuthor"""
        self.helperFunction()

    @weight(5)
    def test_virtual2(self):
        """ test virtual 2: getIsPublic"""
        self.helperFunction()

    @weight(5)
    def test_virtual3(self):
        """ test virtual 3: toString"""
        self.helperFunction()

    @weight(5)
    def test_virtual3(self):
        """ test virtual 3: toString"""
        self.helperFunction()

    @weight(5)
    def test_readpost(self):
        """ test read post: toString"""
        self.helperFunction()

    @weight(10)
    def test_readwritepost(self):
        """ test read and write post: toString"""
        self.helperFunction()


    # test 3: compile
    # test 18: post methods
    # test 14: incoming post methods
    # test 15: virtual methods
    # test 15: readPost, writePost
    # test 10: commandline

    @weight(3)
    def test_commandline_11a(self):
        """ commandline 11a: DisplayPosts """
        test = subprocess.Popen(["./social_network","users.txt", "posts.txt"],
                                stdin=subprocess.PIPE,
                                stdout=subprocess.PIPE,
                                stderr=subprocess.PIPE)
        out,err = test.communicate(input=b"11 Lillie Cain 10\nx\n", timeout=1)
        out = out.strip().decode('utf-8')
        err = err.strip().decode('utf-8')

        # TODO
        self.assertTrue( out.count("iked by") == 5, msg=out)
        self.assertTrue( out.count("wrote:") == 2, msg=out)
        self.assertTrue( out.count("(private)") == 1, msg=out)
        test.terminate()

    @weight(3)
    def test_commandline_11b(self):
        """ commandline 11b: DisplayPosts """
        test = subprocess.Popen(["./social_network","users.txt","posts.txt"],
                                stdin=subprocess.PIPE,
                                stdout=subprocess.PIPE,
                                stderr=subprocess.PIPE)

        out,err = test.communicate(input=b"11 Lillie Cain 4\nx\n", timeout=1)
        out = out.strip().decode('utf-8')
        err = err.strip().decode('utf-8')

        # TODO
        self.assertTrue( out.count("iked by") == 4, msg=out)
        self.assertTrue( out.count("wrote:") == 2, msg=out)
        self.assertTrue( out.count("(private)") == 0, msg=out)

    @weight(3)
    def test_commandline_11c(self):
        """ commandline 11c: DisplayPosts """
        test = subprocess.Popen(["./social_network","users.txt","posts.txt"],
                                stdin=subprocess.PIPE,
                                stdout=subprocess.PIPE,
                                stderr=subprocess.PIPE)

        out,err = test.communicate(input=b"11 Lillie Cain 1\nx\n", timeout=1)
        out = out.strip().decode('utf-8')
        err = err.strip().decode('utf-8')

        # TODO
        self.assertTrue( out.count("iked by") == 1, msg=out)
        self.assertTrue( out.count("wrote:") == 1, msg=out)
        self.assertTrue( out.count("(private)") == 0, msg=out)
 
        test.terminate()



