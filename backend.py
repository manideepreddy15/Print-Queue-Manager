import subprocess

def add_job(job_name):
    return subprocess.getoutput(f'print_queue.exe add "{job_name}"')

def process_job():
    return subprocess.getoutput('print_queue.exe process')

def show_queue():
    return subprocess.getoutput('print_queue.exe show')
