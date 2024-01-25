import unittest
from gradescope_utils.autograder_utils.decorators import weight
from gradescope_utils.autograder_utils.decorators import visibility
import subprocess
import inspect
import io


class TestDiff(unittest.TestCase):

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



