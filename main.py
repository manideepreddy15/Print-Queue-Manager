import streamlit as st
import backend

st.title("🖨️ Print Queue Manager")

menu = ["Add Print Job", "Process Print Job", "Show Pending Jobs"]
choice = st.sidebar.radio("Select Action", menu)

if choice == "Add Print Job":
    job = st.text_input("Enter document name:")
    if st.button("Add Job"):
        output = backend.add_job(job)
        st.success(output)

elif choice == "Process Print Job":
    if st.button("Process"):
        output = backend.process_job()
        st.info(output)

elif choice == "Show Pending Jobs":
    output = backend.show_queue()
    st.code(output)

