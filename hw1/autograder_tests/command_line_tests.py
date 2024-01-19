import unittest
from gradescope_utils.autograder_utils.decorators import weight
from gradescope_utils.autograder_utils.decorators import visibility
import subprocess
import inspect
import io


class TestDiff(unittest.TestCase):
    def setUp(self):
        pass

    @weight(2.5)
    def test_commandline_1(self):
        """ commandline 1 and 4: Add User then Print Users """
        test = subprocess.Popen(["./social_network","users.txt"],
                                stdin=subprocess.PIPE, 
                                stdout=subprocess.PIPE, 
                                stderr=subprocess.PIPE)
        out,err = test.communicate(input=b"1 Test User 2000 94305\n4\n7\n", timeout=1)
        out = out.strip().decode('utf-8')
        err = err.strip().decode('utf-8')
        test.kill()

        self.assertTrue( "Test User" in out, msg="stdout: " + out + ", stderr: " + err)
        test.terminate()



    @weight(2.5)
    def test_commandline_2(self):
        """ commandline 2 and 5: Add Connection then Print friends"""
        test = subprocess.Popen(["./social_network","users.txt"],
                                stdin=subprocess.PIPE,
                                stdout=subprocess.PIPE, 
                                stderr=subprocess.PIPE)
        out,err = test.communicate(input=b"2 Lillie Cain Joyce Baldwin\n5 Lillie Cain\n7\n", timeout=1)
        out = out.strip().decode('utf-8')
        err = err.strip().decode('utf-8')
        test.kill()

        self.assertTrue( "Joyce Baldwin" in out, msg="stdout:\n" + out + "\nstderr:\n" + err)
        test.terminate()


    @weight(2.5)
    def test_commandline_3(self):
        """ commandline 3: Remove Connection then print friends """
        test = subprocess.Popen(["./social_network","users.txt"],
                                stdin=subprocess.PIPE,
                                stdout=subprocess.PIPE, 
                                stderr=subprocess.PIPE)
        out,err = test.communicate(input=b"3 Lillie Cain Nicholas Nunez\n5 Lillie Cain\n7\n", timeout=1)
        out = out.strip().decode('utf-8')
        err = err.strip().decode('utf-8')
        test.kill()

        self.assertTrue( "Nicholas Nunez" not in out, msg="stdout:\n" + out + "\nstderr:\n" + err)
        test.terminate()


    @weight(2.5)
    def test_commandline_4(self):
        """ commandline 4: List Users (checks if it lists the 148 users) """
        test = subprocess.Popen(["./social_network","users.txt"],
                                stdin=subprocess.PIPE,
                                stdout=subprocess.PIPE, 
                                stderr=subprocess.PIPE)
        out,err = test.communicate(input=b"4\n7\n", timeout=1)
        out = out.strip().decode('utf-8')
        err = err.strip().decode('utf-8')
        test.kill()

        self.assertTrue( out.count("\n") >= 148, msg=out+"Not printing users.")
        test.terminate()



    @weight(2.5)
    def test_commandline_5a(self):
        """ commandline 5a: List Friends """
        test = subprocess.Popen(["./social_network","users.txt"],
                                stdin=subprocess.PIPE, 
                                stdout=subprocess.PIPE, 
                                stderr=subprocess.PIPE)
        out,err = test.communicate(input=b"5 Aled Montes\n7\n", timeout=1)
        out = out.strip().decode('utf-8')
        err = err.strip().decode('utf-8')
        test.kill()

        self.assertTrue( out.count("\n") >= 10, msg="stdout:\n" + out + "\nstderr:\n" + err)
        test.terminate()


    @weight(2.5)
    def test_commandline_5b(self):
        """ commandline 5b: List Friends (test no crash on unknown user) """
        test = subprocess.Popen(["./social_network","users.txt"],
                                stdin=subprocess.PIPE, 
                                stdout=subprocess.PIPE, 
                                stderr=subprocess.PIPE)
        out,err = test.communicate(input=b"5 asdf asdf\n7\n", timeout=1)
        out = out.strip().decode('utf-8')
        err = err.strip().decode('utf-8')
        test.kill()
        self.assertTrue( test.returncode == 0 or test.returncode == 1, msg="return code is not 0 or 1.\nstdout:\n" + out + "\nstderr:\n" + err)
        test.terminate()


    @weight(2.5)
    def test_commandline_6(self):
        """ commandline 6: Write users """
        test = subprocess.Popen(["./social_network","users.txt"],
                                stdin=subprocess.PIPE, 
                                stdout=subprocess.PIPE, 
                                stderr=subprocess.PIPE)
        out,err = test.communicate(input=b"6 tmp.txt\n7\n", timeout=1)
        out = out.strip().decode('utf-8')
        err = err.strip().decode('utf-8')
        test.kill()
        test.terminate()

        test = subprocess.Popen(["./social_network","tmp.txt"],
                                stdin=subprocess.PIPE,
                                stdout=subprocess.PIPE, 
                                stderr=subprocess.PIPE)
        out,err = test.communicate(input=b"4\n7\n", timeout=1)
        out = out.strip().decode('utf-8')
        err = err.strip().decode('utf-8')
        test.kill()

        self.assertTrue( out.count("\n") >= 148, msg=out+"Not printing users.")
        test.terminate()


    @weight(2.5)
    def test_commandline_7(self):
        """ commandline 7: Exit """
        test = subprocess.Popen(["./social_network","users.txt"],
                                stdin=subprocess.PIPE, 
                                stdout=subprocess.PIPE, 
                                stderr=subprocess.PIPE)
        out,err = test.communicate(input=b"1000\n", timeout=1)
        out = out.strip().decode('utf-8')
        err = err.strip().decode('utf-8')
        test.kill()
        self.assertTrue( test.returncode == 0 or test.returncode == 1, msg="return code is not 0 or 1.\nstdout:\n" + out + "\nstderr:\n" + err)
        test.terminate()







