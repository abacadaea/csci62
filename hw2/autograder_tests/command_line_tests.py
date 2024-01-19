import unittest
from gradescope_utils.autograder_utils.decorators import weight
from gradescope_utils.autograder_utils.decorators import visibility
import subprocess
import inspect
import io


class TestDiff(unittest.TestCase):
    def setUp(self):
        pass

    @weight(3)
    def test_compile(self):
        #Title used by Gradescope
        """Clean Compile: Run student's makefile"""

        test = subprocess.Popen(["make"], stdout=subprocess.PIPE, stderr=subprocess.PIPE, timeout=1)
        output = test.stderr.decode('utf-8').strip()
        test.kill()

        # Standard unit test case with an associated error message
        self.assertTrue( output == "", msg=output)
        test.terminate()

    @weight(3)
    def test_commandline_7(self):
        """ commandline 7: Shortest Path """
        test = subprocess.Popen(["./social_network","users.txt"],
                                stdin=subprocess.PIPE,
                                stdout=subprocess.PIPE,
                                stderr=subprocess.PIPE)
        out,err = test.communicate(input=b"7 Aled Montes Sandhya Krish\n100\n", timeout=1)
        out = out.strip().decode('utf-8')
        err = err.strip().decode('utf-8')
        test.kill()

        self.assertTrue( "istance: 2" in out, msg="Distance: 2 not in output\n" + out+"\n\n"+err)
        self.assertTrue( "Aled Montes" in out, msg="Aled Montes not in output\n" + out+"\n\n"+err)
        self.assertTrue( "Sandhya Krish" in out, msg="Sandhya Krish not in output\n" + out+"\n\n"+err)
        self.assertTrue( out.count("->") == 2, msg=out+"\n\n"+err)
        test.terminate()



    @weight(3)
    def test_commandline_8(self):
        """ commandline 8: Distance User """
        test = subprocess.Popen(["./social_network","path5.txt"],
                                stdin=subprocess.PIPE,
                                stdout=subprocess.PIPE,
                                stderr=subprocess.PIPE)
        out,err = test.communicate(input=b"8 Lilly Flynn 4\n100\n", timeout=1)
        out = out.strip().decode('utf-8')
        err = err.strip().decode('utf-8')
        test.kill()

        self.assertTrue( out.count("Aled Montes") == 2, msg=out+"\n\n"+err)
        self.assertTrue( out.count("Sandhya Krish") == 1, msg=out+"\n\n"+err)
        self.assertTrue( out.count("Haaris George") == 1, msg=out+"\n\n"+err)
        self.assertTrue( out.count("Alysha Gray") == 1, msg=out+"\n\n"+err)
        self.assertTrue( out.count("Lilly Flynn") == 1, msg=out+"\n\n"+err)
        self.assertTrue( out.count("->") == 4, msg=out+"\n\n"+err)
        test.terminate()


    @weight(3)
    def test_commandline_9(self):
        """ commandline 9: Suggest Friends """
        test = subprocess.Popen(["./social_network","users.txt"],
                                stdin=subprocess.PIPE,
                                stdout=subprocess.PIPE,
                                stderr=subprocess.PIPE)
        out,err = test.communicate(input=b"9 Aled Montes\n100\n", timeout=1)
        out = out.strip().decode('utf-8')
        err = err.strip().decode('utf-8')
        test.kill()

        self.assertTrue( out.count("core: 5") == 4, msg=out+"\n\n"+err)
        self.assertTrue( out.count("Astrid Cantrell") == 1, msg=out+"\n\n"+err)
        self.assertTrue( out.count("Ellie-Mae Vega") == 1, msg=out+"\n\n"+err)
        self.assertTrue( out.count("Alina Baird") == 1, msg=out+"\n\n"+err)
        self.assertTrue( out.count("Trinity Foley") == 1, msg=out+"\n\n"+err)
        test.terminate()


    @weight(3)
    def test_commandline_10(self):
        """ commandline 10: Groups """
        test = subprocess.Popen(["./social_network","match4.txt"],
                                stdin=subprocess.PIPE,
                                stdout=subprocess.PIPE,
                                stderr=subprocess.PIPE)
        out,err = test.communicate(input=b"10\n100\n", timeout=1)
        out = out.strip().decode('utf-8')
        err = err.strip().decode('utf-8')
        test.kill()

        self.assertTrue( out.count("et 1") == 1, msg=out)
        self.assertTrue( out.count("et 2") == 1, msg=out)
        self.assertTrue( out.count("et 3") == 0, msg=out)
        test.terminate()



